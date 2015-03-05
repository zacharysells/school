#!/usr/bin/perl

$num_args = $#ARGV + 1;
if($num_args != 1)
{
  print "Incorrect number of arguments. One argument expected\n";
  exit;
}

open (FILE, "<$ARGV[0]");

# Count occurences of each unique email address.
while($line = <FILE>)
{
  # Count 'to' addresses.
  if($line =~ /to=<([^<>]*)>/)
  {
    $count = $to_addresses{$1};
    ++$count;
    $to_addresses{$1} = $count;
  }

  # Count 'from' addresses.
  if($line =~ /from=<([^<>]*)>/)
  {
    $count = $from_addresses{$1};
    ++$count;
    $from_addresses{$1} = $count;
  }
}

print "=====================================================================\n";
print "Top 5 To addresses:\n";
print "=====================================================================\n";

# Print 5 most frequent 'to' addresses.
$count = 5;
foreach $address (sort {$to_addresses{$b} <=> $to_addresses{$a}} keys %to_addresses)
{
  if($count == 0)
  {
    last;
  }
  print "To $address: $to_addresses{$address}\n";
  --$count;
}

print "=====================================================================\n";
print "Top 5 From addresses:\n";
print "=====================================================================\n";

# Print 5 most frequent 'from' addresses.
$count = 5;
foreach $address (sort {$from_addresses{$b} <=> $from_addresses{$a}} keys %from_addresses)
{
  if($count == 0)
  {
    last;
  }
  print "From $address: $from_addresses{$address}\n";
  --$count;
}
