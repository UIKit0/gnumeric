/*
 * Documentation for those functions where inline documentation is
 * not appropriate, for example because the source code was imported
 * from elsewhere.
 */

/* ------------------------------------------------------------------------- */

/**
 * log1pmx:
 * @x: a number
 *
 * Returns: log(1+@x)-@x with less rounding error than the naive formula,
 * especially for small values of @x.
 */


/**
 * pow1p:
 * @x: a number
 * @y: a number
 *
 * Returns: The result of (1+@x)^@y with less rounding error than the
 * naive formula.
 */


/**
 * pow1pm1:
 * @x: a number
 * @y: a number
 *
 * Returns: The result of (1+@x)^@y-1 with less rounding error than the
 * naive formula.
 */

/**
 * gnm_cot:
 * @x: an angle in radians
 *
 * Returns: The co-tangent of the given angle.
 */

/**
 * gnm_acot:
 * @x: a number
 *
 * Returns: The inverse co-tangent of the given number.
 */

/**
 * gnm_coth:
 * @x: a number.
 *
 * Returns: The hyperbolic co-tangent of the given number.
 */

/**
 * gnm_acoth:
 * @x: a number
 *
 * Returns: The inverse hyperbolic co-tangent of the given number.
 */

/**
 * beta:
 * @a: a number
 * @b: a number
 *
 * Returns: the beta function evaluated at @a and @b.
 */

/**
 * lbeta3:
 * @a: a number
 * @b: a number
 * @sign: (out): the sign
 *
 * Returns: the logarithm of the absolute value of the beta function
 * evaluated at @a and @b.  The sign will be stored in @sign as -1 or
 * +1.  This function is useful because the result of the beta
 * function can be too large for doubles.
 */

/* ------------------------------------------------------------------------- */

/**
 * dnorm:
 * @x: observation
 * @mu: mean of the distribution
 * @sigma: standard deviation of the distribution
 * @give_log: if %TRUE, log of the result will be returned instead
 *
 * Returns: density of the normal distribution.
 */

/**
 * pnorm:
 * @x: observation
 * @mu: mean of the distribution
 * @sigma: standard deviation of the distribution
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, log of the result will be returned instead
 *
 * Returns: cumulative density of the normal distribution.
 */

/**
 * qnorm:
 * @p: probability
 * @mu: mean of the distribution
 * @sigma: standard deviation of the distribution
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, @p is given as log probability
 *
 * Returns: the observation with cumulative probability @p for the
 * normal distribution.
 */

/* ------------------------------------------------------------------------- */

/**
 * dlnorm:
 * @x: observation
 * @logmean: mean of the underlying normal distribution
 * @logsd: standard deviation of the underlying normal distribution
 * @give_log: if %TRUE, log of the result will be returned instead
 *
 * Returns: density of the normal distribution.
 */

/**
 * plnorm:
 * @x: observation
 * @logmean: mean of the underlying normal distribution
 * @logsd: standard deviation of the underlying normal distribution
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, log of the result will be returned instead
 *
 * Returns: cumulative density of the normal distribution.
 */

/**
 * qlnorm:
 * @p: probability
 * @logmean: mean of the underlying normal distribution
 * @logsd: standard deviation of the underlying normal distribution
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, @p is given as log probability
 *
 * Returns: the observation with cumulative probability @p for the
 * log normal distribution.
 */

/* ------------------------------------------------------------------------- */

/**
 * dgamma:
 * @x: observation
 * @shape: the shape parameter of the distribution
 * @scale: the scale parameter of the distribution
 * @give_log: if %TRUE, log of the result will be returned instead
 *
 * Returns: density of the gamma distribution.
 */

/**
 * pgamma:
 * @x: observation
 * @shape: the shape parameter of the distribution
 * @scale: the scale parameter of the distribution
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, log of the result will be returned instead
 *
 * Returns: cumulative density of the gamma distribution.
 */

/**
 * qgamma:
 * @p: probability
 * @shape: the shape parameter of the distribution
 * @scale: the scale parameter of the distribution
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, @p is given as log probability
 *
 * Returns: the observation with cumulative probability @p for the
 * gamma distribution.
 */

/* ------------------------------------------------------------------------- */

/**
 * dbeta:
 * @x: observation
 * @a: the first shape parameter of the distribution
 * @b: the second scale parameter of the distribution
 * @give_log: if %TRUE, log of the result will be returned instead
 *
 * Returns: density of the beta distribution.
 */

/**
 * pbeta:
 * @x: observation
 * @a: the first shape parameter of the distribution
 * @b: the second scale parameter of the distribution
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, log of the result will be returned instead
 *
 * Returns: cumulative density of the beta distribution.
 */

/**
 * qbeta:
 * @p: probability
 * @a: the first shape parameter of the distribution
 * @b: the second scale parameter of the distribution
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, @p is given as log probability
 *
 * Returns: the observation with cumulative probability @p for the
 * beta distribution.
 */

/* ------------------------------------------------------------------------- */

/**
 * dt:
 * @x: observation
 * @n: the number of degrees of freedom of the distribution
 * @give_log: if %TRUE, log of the result will be returned instead
 *
 * Returns: density of the Student t distribution.
 */

/**
 * pt:
 * @x: observation
 * @n: the number of degrees of freedom of the distribution
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, log of the result will be returned instead
 *
 * Returns: cumulative density of the Student t distribution.
 */

/**
 * qt:
 * @p: probability
 * @n: the number of degrees of freedom of the distribution
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, @p is given as log probability
 *
 * Returns: the observation with cumulative probability @p for the
 * Student t distribution.
 */

/* ------------------------------------------------------------------------- */

/**
 * df:
 * @x: observation
 * @n1: the first number of degrees of freedom of the distribution
 * @n2: the first number of degrees of freedom of the distribution
 * @give_log: if %TRUE, log of the result will be returned instead
 *
 * Returns: density of the F distribution.
 */

/**
 * pf:
 * @x: observation
 * @n1: the first number of degrees of freedom of the distribution
 * @n2: the first number of degrees of freedom of the distribution
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, log of the result will be returned instead
 *
 * Returns: cumulative density of the F distribution.
 */

/**
 * qf:
 * @p: probability
 * @n1: the first number of degrees of freedom of the distribution
 * @n2: the first number of degrees of freedom of the distribution
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, @p is given as log probability
 *
 * Returns: the observation with cumulative probability @p for the
 * F distribution.
 */

/* ------------------------------------------------------------------------- */

/**
 * dgeom:
 * @x: observation
 * @psuc: the probability of success in each trial
 * @give_log: if %TRUE, log of the result will be returned instead
 *
 * Returns: density of the geometric distribution.
 */

/**
 * pgeom:
 * @x: observation
 * @psuc: the probability of success in each trial
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, log of the result will be returned instead
 *
 * Returns: cumulative density of the geometric distribution.
 */

/**
 * qgeom:
 * @p: probability
 * @psuc: the probability of success in each trial
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, @p is given as log probability
 *
 * Returns: the observation with cumulative probability @p for the
 * geometric distribution.
 */

/* ------------------------------------------------------------------------- */

/**
 * dchisq:
 * @x: observation
 * @df: the number of degrees of freedom of the distribution
 * @give_log: if %TRUE, log of the result will be returned instead
 *
 * Returns: density of the &#x1D712;&#xb2; distribution.
 */

/**
 * pchisq:
 * @x: observation
 * @df: the number of degrees of freedom of the distribution
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, log of the result will be returned instead
 *
 * Returns: cumulative density of the &#x1D712;&#xb2; distribution.
 */

/**
 * qchisq:
 * @p: probability
 * @df: the number of degrees of freedom of the distribution
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, @p is given as log probability
 *
 * Returns: the observation with cumulative probability @p for the
 * &#x1D712;&#xb2; distribution.
 */

/* ------------------------------------------------------------------------- */

/**
 * dweibull:
 * @x: observation
 * @shape: the shape parameter of the distribution
 * @scale: the scale parameter of the distribution
 * @give_log: if %TRUE, log of the result will be returned instead
 *
 * Returns: density of the Weibull distribution.
 */

/**
 * pweibull:
 * @x: observation
 * @shape: the shape parameter of the distribution
 * @scale: the scale parameter of the distribution
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, log of the result will be returned instead
 *
 * Returns: cumulative density of the Weibull distribution.
 */

/**
 * qweibull:
 * @p: probability
 * @shape: the shape parameter of the distribution
 * @scale: the scale parameter of the distribution
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, @p is given as log probability
 *
 * Returns: the observation with cumulative probability @p for the
 * Weibull distribution.
 */

/* ------------------------------------------------------------------------- */

/**
 * dpois:
 * @x: observation
 * @lambda: the mean of the distribution
 * @give_log: if %TRUE, log of the result will be returned instead
 *
 * Returns: density of the Poisson distribution.
 */

/**
 * ppois:
 * @x: observation
 * @lambda: the mean of the distribution
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, log of the result will be returned instead
 *
 * Returns: cumulative density of the Poisson distribution.
 */

/**
 * qpois:
 * @p: probability
 * @lambda: the mean of the distribution
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, @p is given as log probability
 *
 * Returns: the observation with cumulative probability @p for the
 * Poisson distribution.
 */

/* ------------------------------------------------------------------------- */

/**
 * dexp:
 * @x: observation
 * @scale: the scale parameter of the distribution
 * @give_log: if %TRUE, log of the result will be returned instead
 *
 * Returns: density of the exponential distribution.
 */

/**
 * pexp:
 * @x: observation
 * @scale: the scale parameter of the distribution
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, log of the result will be returned instead
 *
 * Returns: cumulative density of the exponential distribution.
 */

/**
 * qexp:
 * @p: probability
 * @scale: the scale parameter of the distribution
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, @p is given as log probability
 *
 * Returns: the observation with cumulative probability @p for the
 * exponential distribution.
 */

/* ------------------------------------------------------------------------- */

/**
 * dbinom:
 * @x: observation
 * @n: the number of trials
 * @psuc: the probability of success in each trial
 * @give_log: if %TRUE, log of the result will be returned instead
 *
 * Returns: density of the binomial distribution.
 */

/**
 * pbinom:
 * @x: observation
 * @n: the number of trials
 * @psuc: the probability of success in each trial
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, log of the result will be returned instead
 *
 * Returns: cumulative density of the binomial distribution.
 */

/**
 * qbinom:
 * @p: probability
 * @n: the number of trials
 * @psuc: the probability of success in each trial
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, @p is given as log probability
 *
 * Returns: the observation with cumulative probability @p for the
 * binomial distribution.
 */

/* ------------------------------------------------------------------------- */

/**
 * dnbinom:
 * @x: observation
 * @n: the number of trials
 * @psuc: the probability of success in each trial
 * @give_log: if %TRUE, log of the result will be returned instead
 *
 * Returns: density of the negative binomial distribution.
 */

/**
 * pnbinom:
 * @x: observation
 * @n: the number of trials
 * @psuc: the probability of success in each trial
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, log of the result will be returned instead
 *
 * Returns: cumulative density of the negative binomial distribution.
 */

/**
 * qnbinom:
 * @p: probability
 * @n: the number of trials
 * @psuc: the probability of success in each trial
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, @p is given as log probability
 *
 * Returns: the observation with cumulative probability @p for the
 * negative binomial distribution.
 */

/* ------------------------------------------------------------------------- */

/**
 * dhyper:
 * @x: observation
 * @r: the number of red balls
 * @b: the number of black balls
 * @n: the number of balls drawn
 * @give_log: if %TRUE, log of the result will be returned instead
 *
 * Returns: density of the hypergeometric distribution.
 */

/**
 * phyper:
 * @x: observation
 * @r: the number of red balls
 * @b: the number of black balls
 * @n: the number of balls drawn
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, log of the result will be returned instead
 *
 * Returns: cumulative density of the hypergeometric distribution.
 */

/**
 * qhyper:
 * @p: probability
 * @r: the number of red balls
 * @b: the number of black balls
 * @n: the number of balls drawn
 * @lower_tail: if %TRUE, the lower tail of the distribution is considered.
 * @log_p: if %TRUE, @p is given as log probability
 *
 * Returns: the observation with cumulative probability @p for the
 * hypergeometric distribution.
 */

/* ------------------------------------------------------------------------- */