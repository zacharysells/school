kconfig ip6tables off #This service filters incomming packets and is not
                        #needed since we're running a NAT network

chkconfig iptables off #This service filters incoming ipv4 packets which        
                       #aren't needed since we're running on a NAT network

chkconfig netfs off #This service mounts network filesystems which can't be used
                    #on a NAT network

chkconfig sshd off #This service is responsible for establishing ssh connections
                   #which aren't used on a NAT network

chkconfig mdmonitor off #This service handles RAID configurations. Our
                        #virutalbox isn't running RAID so this isn't needed

