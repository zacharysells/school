#!/usr/bin/perl

$num_args = $#ARGV + 1;
if($num_args == 0)
{
  print "Incorrect number of arguments. One or more arguments expected\n";
  exit;
}

# Nothing to do if no patterns are supplied to command line.
if($num_args == 1)
{
  exit;
}

if(! -f $ARGV[0])
{
  print "First argument must be a text file\n";
  exit;
}

# Store file contents into array.
open(FILE, "<$ARGV[0]");
@lines = <FILE>;
close(FILE);

# Reopen file for writing.
open(FILE, ">$ARGV[0]");

# Add all arguments except the first one to the pattern matching.
$patterns = join("|", @ARGV[1..$#ARGV]);
print "$patterns\n";
foreach $line (@lines)
{
  print FILE $line unless ($line =~ m/$patterns/);
}

close FILE;
