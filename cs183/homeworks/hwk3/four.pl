#!/usr/bin/perl

open (FILE, "<log4");
$num_blocked = 0;
while($line = <FILE>)
{

  # Count number of blocked messages by dnsbl.sorbs.net
  if($line =~ /(blocked using dnsbl.sorbs.net)/)
  {
    ++$num_blocked;
  }

  # Count unique ip addresses
  if($line =~ /(\d+\.\d+\.\d+\.\d+)/)
  {
    $ips{$1} = 0;
  }

  # Count unique 'to' addresses.
  if($line =~ /to=<([^<>]*)>/)
  {
    $to_addresses{$1} = 0;
  }

  # Count unique 'from' addresses.
  if($line =~ /from=<([^<>]*)>/)
  {
    $from_addresses{$1} = 0
  }
}
$num_ips = scalar(keys(%ips));
$num_from_addresses = scalar(keys(%from_addresses));
$num_to_addresses = scalar(keys(%to_addresses));

print "$num_blocked blocked\n";
print "$num_ips unique IP's\n";
print "$num_from_addresses unique from addresses\n";
print "$num_to_addresses unique to addresses\n";
