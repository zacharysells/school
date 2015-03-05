#!/usr/bin/perl

$num_args = $#ARGV + 1;

if ($num_args != 1)
{
  print "Incorrect number of args. One argument expected\n";
  exit;
}

use File::Slurp;
$lines = read_file($ARGV[0]);
$pos_count = 0;
$amavis_count = 0;

# Two for-loops used because single digit numbers do not need preceeding '0' in
# regex pattern
for $i (0..9)
{
  $pos_pattern = "^Mar  1 00:0$i:...*postfix.*reject.*\$";
  @pos_matches = $lines =~ /$pos_pattern/mg;
  $pos_count = $#pos_matches + 1;

  $amavis_pattern = "^Mar  1 00:0$i:...*amavis.*Not-Delivered.*\$";
  @amavis_matches = $lines =~ /$amavis_pattern/mg;
  $amavis_count = $#amavis_matches + 1;

  print "Mar 1 00:0$i [postfix:$pos_count] [amavis:$amavis_count]\n"
}

for $i (10..59)
{
  $pos_pattern = "^Mar  1 00:$i:...*postfix.*reject.*\$";
  @pos_matches = $lines =~ /$pos_pattern/mg;
  $pos_count = $#pos_matches + 1;

  $amavis_pattern = "^Mar  1 00:$i:...*amavis.*Not-Delivered.*\$";
  @amavis_matches = $lines =~ /$amavis_pattern/mg;
  $amavis_count = $#amavis_matches + 1;

  print "Mar 1 00:0$i [postfix:$pos_count] [amavis:$amavis_count]\n"
}
