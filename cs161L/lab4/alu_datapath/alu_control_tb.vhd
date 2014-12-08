--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   14:02:48 02/22/2014
-- Design Name:   
-- Module Name:   /home/zacharysells/Documents/cs161L/lab4/alu_datapath/alu_control_tb.vhd
-- Project Name:  alu_datapath
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: alu_control
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
use STD.textio.all;                     -- basic I/O
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY alu_control_tb IS
END alu_control_tb;
 
ARCHITECTURE behavior OF alu_control_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT alu_control
    PORT(
         alu_op : IN  std_logic_vector(1 downto 0);
         instruction_5_0 : IN  std_logic_vector(5 downto 0);
         alu_out : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal alu_op : std_logic_vector(1 downto 0) := (others => '0');
   signal instruction_5_0 : std_logic_vector(5 downto 0) := (others => '0');

 	--Outputs
   signal alu_out : std_logic_vector(3 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: alu_control PORT MAP (
          alu_op => alu_op,
          instruction_5_0 => instruction_5_0,
          alu_out => alu_out
        );

   -- Clock process definitions
 

   -- Stimulus process
   stim_proc: process
	variable mline : line;
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
		
		--Testing op1
		Report("Testing op1!");
		alu_op <= "00";
		instruction_5_0 <= "000000";
		wait for 2 ns;
		assert alu_out = "0010" Report("reg_dst test 1 incorrect") severity Warning;
		
		--Testing op2
		Report("Testing op2!");
		alu_op <= "11";
		instruction_5_0 <= "000000";
		wait for 2 ns;
		assert alu_out = "0010" Report("reg_dst test 2 incorrect") severity Warning;
		
		--Testing op3
		Report("Testing op3!");
		alu_op <= "11";
		instruction_5_0 <= "000000";
		wait for 2 ns;
		assert alu_out = "0010" Report("reg_dst test 3 incorrect") severity Warning;
		
		--Testing op4
		Report("Testing op4!");
		alu_op <= "11";
		instruction_5_0 <= "000010";
		wait for 2 ns;
		assert alu_out = "0110" Report("reg_dst test 4 incorrect") severity Warning;
		
		--Testing op5
		Report("Testing op5!");
		alu_op <= "11";
		instruction_5_0 <= "000100";
		wait for 2 ns;
		assert alu_out = "0000" Report("reg_dst test 5 incorrect") severity Warning;
		
		--Testing op6
		Report("Testing op6!");
		alu_op <= "11";
		instruction_5_0 <= "000101";
		wait for 2 ns;
		assert alu_out = "0001" Report("reg_dst test 6 incorrect") severity Warning;
		
		--Testing op7
		Report("Testing op7!");
		alu_op <= "11";
		instruction_5_0 <= "001010";
		wait for 2 ns;
		assert alu_out = "0111" Report("reg_dst test 7 incorrect") severity Warning;

      -- insert stimulus here 

      wait;
   end process;

END;
