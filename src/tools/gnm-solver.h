#ifndef _TOOLS_GNM_SOLVER_H_
#define _TOOLS_GNM_SOLVER_H_

#include <glib-object.h>
#include <gnumeric.h>
#include <solver.h>

G_BEGIN_DECLS

/* ------------------------------------------------------------------------- */

typedef enum {
	GNM_SOLVER_RESULT_NONE,
	GNM_SOLVER_RESULT_FEASIBLE,
	GNM_SOLVER_RESULT_OPTIMAL,
	GNM_SOLVER_RESULT_INFEASIBLE,
	GNM_SOLVER_RESULT_UNBOUNDED
} GnmSolverResultQuality;


GType gnm_solver_status_get_type (void);
#define GNM_SOLVER_STATUS_TYPE (gnm_solver_status_get_type ())

typedef enum {
	GNM_SOLVER_STATUS_READY,
	GNM_SOLVER_STATUS_PREPARING,
	GNM_SOLVER_STATUS_PREPARED,
	GNM_SOLVER_STATUS_RUNNING,
	GNM_SOLVER_STATUS_DONE,
	GNM_SOLVER_STATUS_ERROR,
	GNM_SOLVER_STATUS_CANCELLED
} GnmSolverStatus;

/* ------------------------------------------------------------------------- */

#define GNM_SOLVER_RESULT_TYPE   (gnm_solver_result_get_type ())
#define GNM_SOLVER_RESULT(o)     (G_TYPE_CHECK_INSTANCE_CAST ((o), GNM_SOLVER_RESULT_TYPE, GnmSolverResult))

typedef struct {
	GObject parent;

	GnmSolverResultQuality quality;
	gnm_float value;
	GnmValue *solution;
} GnmSolverResult;

typedef struct {
	GObjectClass parent_class;
} GnmSolverResultClass;

GType gnm_solver_result_get_type  (void);

/* ------------------------------------------------------------------------- */
/* Generic Solver class. */

#define GNM_SOLVER_TYPE        (gnm_solver_get_type ())
#define GNM_SOLVER(o)          (G_TYPE_CHECK_INSTANCE_CAST ((o), GNM_SOLVER_TYPE, GnmSolver))
#define GNM_SOLVER_CLASS(k)    (G_TYPE_CHECK_CLASS_CAST ((k), GNM_SOLVER_TYPE, GnmSolverClass))
#define GNM_IS_SOLVER(o)       (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNM_SOLVER_TYPE))

typedef struct {
	GObject parent;

	GnmSolverStatus status;
	SolverParameters *params;
	GnmSolverResult *result;
} GnmSolver;

typedef struct {
	GObjectClass parent_class;

	gboolean (*prepare) (GnmSolver *solver,
			     WorkbookControl *wbc, GError **err);
	gboolean (*start) (GnmSolver *solver,
			   WorkbookControl *wbc, GError **err);
	gboolean (*stop) (GnmSolver *solver, GError **err);
} GnmSolverClass;

GType gnm_solver_get_type  (void);

gboolean gnm_solver_prepare (GnmSolver *solver,
			     WorkbookControl *wbc, GError **err);
gboolean gnm_solver_start (GnmSolver *solver,
			   WorkbookControl *wbc, GError **err);
gboolean gnm_solver_stop (GnmSolver *solver, GError **err);

void gnm_solver_set_status (GnmSolver *solver, GnmSolverStatus status);

void gnm_solver_store_result (GnmSolver *solver);

gboolean gnm_solver_finished (GnmSolver *solver);

gboolean gnm_solver_saveas (GnmSolver *solver, WorkbookControl *wbc,
			    GOFileSaver *fs,
			    const char *template, char **filename,
			    GError **err);

/* ------------------------------------------------------------------------- */
/* Solver subclass for subprocesses. */

#define GNM_SUB_SOLVER_TYPE     (gnm_sub_solver_get_type ())
#define GNM_SUB_SOLVER(o)       (G_TYPE_CHECK_INSTANCE_CAST ((o), GNM_SUB_SOLVER_TYPE, GnmSubSolver))
#define GNM_SUB_SOLVER_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), GNM_SUB_SOLVER_TYPE, GnmSubSolverClass))
#define GNM_IS_SUB_SOLVER(o)    (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNM_SUB_SOLVER_TYPE))

typedef struct {
	GnmSolver parent;

	char *program_filename;

	GPid child_pid;
	guint child_watch;

	GChildWatchFunc child_exit;
	gpointer exit_data;

	gint fd[3];
	GIOChannel *channels[3];
	guint channel_watches[3];
	GIOFunc io_funcs[3];
	gpointer io_funcs_data[3];
} GnmSubSolver;

typedef struct {
	GnmSolverClass parent_class;
} GnmSubSolverClass;

GType gnm_sub_solver_get_type  (void);

void gnm_sub_solver_clear (GnmSubSolver *subsol);

gboolean gnm_sub_solver_spawn
		(GnmSubSolver *subsol,
		 char **argv,
		 GSpawnChildSetupFunc child_setup, gpointer setup_data,
		 GChildWatchFunc child_exit, gpointer exit_data,
		 GIOFunc io_stdout, gpointer stdout_data,
		 GIOFunc io_stderr, gpointer stderr_data,
		 GError **err);

void gnm_sub_solver_flush (GnmSubSolver *subsol);

/* ------------------------------------------------------------------------- */

#define GNM_SOLVER_FACTORY_TYPE        (gnm_solver_factory_get_type ())
#define GNM_SOLVER_FACTORY(o)          (G_TYPE_CHECK_INSTANCE_CAST ((o), GNM_SOLVER_FACTORY_TYPE, GnmSolverFactory))
#define GNM_IS_SOLVER_FACTORY(o)       (G_TYPE_CHECK_INSTANCE_TYPE ((o), GNM_SOLVER_FACTORY_TYPE))

typedef GnmSolver * (*GnmSolverCreator) (GnmSolverFactory *,
					 SolverParameters *);

struct GnmSolverFactory_ {
	GObject parent;

	char *id;
	char *name; /* Already translated */
	SolverModelType type;
	GnmSolverCreator creator;
};

typedef struct {
	GObjectClass parent_class;
} GnmSolverFactoryClass;

GType gnm_solver_factory_get_type (void);

GnmSolverFactory *gnm_solver_factory_new (const char *id,
					  const char *name,
					  SolverModelType type,
					  GnmSolverCreator creator);
GnmSolver *gnm_solver_factory_create (GnmSolverFactory *factory,
				      SolverParameters *param);

GSList *gnm_solver_db_get (void);
void gnm_solver_db_register (GnmSolverFactory *factory);
void gnm_solver_db_unregister (GnmSolverFactory *factory);

/* ------------------------------------------------------------------------- */

G_END_DECLS

#endif /* _TOOLS_GNM_SOLVER_H_ */