--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   22:10:45 02/20/2014
-- Design Name:   
-- Module Name:   /home/zacharysells/Documents/cs161L/lab4/alu_datapath/control_unit_tb.vhd
-- Project Name:  alu_datapath
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: control_unit
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY control_unit_tb IS
END control_unit_tb;
 
ARCHITECTURE behavior OF control_unit_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT control_unit
    PORT(
         instr_op : IN  std_logic_vector(5 downto 0);
         reg_dst : OUT  std_logic;
         branch : OUT  std_logic;
         mem_read : OUT  std_logic;
         mem_to_reg : OUT  std_logic;
         alu_op : OUT  std_logic_vector(1 downto 0);
         mem_write : OUT  std_logic;
         alu_src : OUT  std_logic;
         reg_write : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal instr_op : std_logic_vector(5 downto 0) := (others => '0');

 	--Outputs
   signal reg_dst : std_logic;
   signal branch : std_logic;
   signal mem_read : std_logic;
   signal mem_to_reg : std_logic;
   signal alu_op : std_logic_vector(1 downto 0);
   signal mem_write : std_logic;
   signal alu_src : std_logic;
   signal reg_write : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: control_unit PORT MAP (
          instr_op => instr_op,
          reg_dst => reg_dst,
          branch => branch,
          mem_read => mem_read,
          mem_to_reg => mem_to_reg,
          alu_op => alu_op,
          mem_write => mem_write,
          alu_src => alu_src,
          reg_write => reg_write
        );
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
		
		--Testing reg_dst
		Report("Testing Reg_dst!");
		instr_op <= "000000";
		wait for 2 ns;
		assert reg_dst = '1' Report("reg_dst test 1 incorrect") severity Warning;
		
		
		instr_op <= "010110";
		wait for 2 ns;
		assert reg_dst = '0' Report("reg_dst test 2 incorrect") severity Warning;
		
		--Testing reg_dst
		Report("Testing Branch!");
		instr_op <= "000100";
		wait for 2 ns;
		assert branch = '1' Report("reg_dst test 1 incorrect") severity Warning;
		
		
		instr_op <= "000000";
		wait for 2 ns;
		assert branch = '0' Report("reg_dst test 2 incorrect") severity Warning;
		
		--Testing mem_read
		Report("Testing MEM_READ!");
		instr_op <= "100011";
		wait for 2 ns;
		assert mem_read = '1' Report("reg_dst test 1 incorrect") severity Warning;
		
		
		instr_op <= "001100";
		wait for 2 ns;
		assert mem_read = '0' Report("reg_dst test 2 incorrect") severity Warning;
		
		--Testing mem_to_reg
		Report("Testing mem_to_reg!");
		instr_op <= "100011";
		wait for 2 ns;
		assert mem_to_reg = '1' Report("reg_dst test 1 incorrect") severity Warning;
		
		
		instr_op <= "001100";
		wait for 2 ns;
		assert mem_to_reg = '0' Report("reg_dst test 2 incorrect") severity Warning;
		
		--Testing alu_op
		Report("Testing alu_op!");
		instr_op <= "000000";
		wait for 2 ns;
		assert alu_op = "10" Report("reg_dst test 1 incorrect") severity Warning;
		
		
		instr_op <= "000100";
		wait for 2 ns;
		assert alu_op = "01" Report("reg_dst test 2 incorrect") severity Warning;
		
		instr_op <= "101100";
		wait for 2 ns;
		assert alu_op = "00" Report("reg_dst test 3 incorrect") severity Warning;
		
		--Testing mem_write
		Report("Testing mem_write!");
		instr_op <= "101011";
		wait for 2 ns;
		assert mem_write = '1' Report("reg_dst test 1 incorrect") severity Warning;
		
		
		instr_op <= "000100";
		wait for 2 ns;
		assert mem_write = '0' Report("reg_dst test 2 incorrect") severity Warning;
		
		--Testing alu_src
		Report("Testing alu_src!");
		instr_op <= "011000";
		wait for 2 ns;
		assert alu_src = '0' Report("reg_dst test 1 incorrect") severity Warning;
		
		instr_op <= "100011";
		wait for 2 ns;
		assert alu_src = '1' Report("reg_dst test 2 incorrect") severity Warning;
		
		instr_op <= "101011";
		wait for 2 ns;
		assert alu_src = '1' Report("reg_dst test 3 incorrect") severity Warning;
		
		--Testing reg_write
		Report("Testing reg_write!");
		instr_op <= "000000";
		wait for 2 ns;
		assert reg_write = '1' Report("reg_dst test 1 incorrect") severity Warning;
		
		instr_op <= "100011";
		wait for 2 ns;
		assert reg_write = '1' Report("reg_dst test 2 incorrect") severity Warning;
		
		instr_op <= "101011";
		wait for 2 ns;
		assert reg_write = '0' Report("reg_dst test 3 incorrect") severity Warning;

      wait;
   end process;

END;
