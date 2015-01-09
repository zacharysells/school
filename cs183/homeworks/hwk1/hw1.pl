#!/usr/bin/perl

foreach my $arg (@ARGV)
{
  open FILE, "<", "$arg" or die $!; #Open file in read only mode

  print <FILE>; #<FILE> contains all unread lines of FILE handle

  close FILE;
}
