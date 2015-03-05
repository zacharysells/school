#!/usr/bin/perl

open (FILE, "<log2");

while($line = <FILE>)
{
  # Count uknown connections.
  if($line =~ m/ connect from unknown(\[\d+\.\d+\.\d+\.\d+\])/)
  {
    ++$unknown;
    $count = $unknown_con{$1};
    ++$count;
    $unknown_con{$1} = $count;
  }

  # Count known connections
  elsif($line =~ m/ connect from .*(\[\d+\.\d+\.\d+\.\d+\])/)
  {
    ++$known;
    $count = $known_con{$1};
    ++$count;
    $known_con{$1} = $count;
  }
}

# Sort unknown connections and print the most frequent one.
$count = 1;
foreach $con (sort {$unknown_con{$b} <=> $unknown_con{$a}} keys %unknown_con)
{
  if($count == 0)
  {
    last;
  }
  print "Total Unknown connections: $unknown - $con accounts for $unknown_con{$con} connections\n";
  --$count;
}

# Sort known connections and print the most frequent one.
$count = 1;
foreach $con (sort {$known_con{$b} <=> $known_con{$a}} keys %known_con)
{
  if($count == 0)
  {
    last;
  }
  print "Total Known connections: $known - $con accounts for $known_con{$con} connections\n";
  --$count;
}

close FILE;
