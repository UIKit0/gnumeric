#!/usr/bin/perl -w
# -----------------------------------------------------------------------------

use strict;
use lib ($0 =~ m|^(.*/)| ? $1 : ".");
use GnumericTest;

my $file = "$samples/formula-tests.gnumeric";

&message ("Check formula gnumeric roundtrip.");
&test_roundtrip ($file,
		 'format' => 'Gnumeric_XmlIO:sax',
		 'ext' => "gnm");

&message ("Check formula ods roundtrip.");
&test_roundtrip ($file,
		 'format' => 'Gnumeric_OpenCalc:odf',
		 'ext' => "ods",
		 'filter2' => "$PERL -p -e '\$_ = \"\" if m{<meta:generator>}'");

my $xls_codepage_filter = "$PERL -p -e '\$_ = \"\" if m{<meta:user-defined meta:name=.msole:codepage.}'";

&message ("Check formula xls/BIFF7 roundtrip.");
&test_roundtrip ($file,
		 'format' => 'Gnumeric_Excel:excel_biff7',
		 'ext' => "xls",
		 'resize' => '16384x256',
		 'filter2' => $xls_codepage_filter);

&message ("Check formula xls/BIFF8 roundtrip.");
&test_roundtrip ($file,
		 'format' => 'Gnumeric_Excel:excel_biff8',
		 'ext' => "xls",
		 'filter2' => $xls_codepage_filter);

&message ("Check formula xlsx roundtrip.");
&test_roundtrip ($file,
		 'format' => 'Gnumeric_Excel:xlsx',
		 'ext' => "xlsx",
		 'resize' => '1048576x16384');
