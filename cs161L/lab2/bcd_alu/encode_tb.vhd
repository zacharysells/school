--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   18:42:37 02/03/2014
-- Design Name:   
-- Module Name:   /home/zacharysells/Documents/cs161L/lab2/bcd_alu/encode_tb.vhd
-- Project Name:  bcd_alu
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: encode
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
USE ieee.std_logic_unsigned.all;
USE ieee.numeric_std.ALL;
USE ieee.std_logic_arith.all;
use STD.textio.all;                     -- basic I/O
use IEEE.std_logic_textio.all;          -- I/O for logic types
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY encode_tb IS
END encode_tb;
 
ARCHITECTURE behavior OF encode_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT encode
    PORT(
         A : IN  std_logic_vector(31 downto 0);
         encoded_A : OUT  std_logic_vector(35 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic_vector(31 downto 0) := (others => '0');

 	--Outputs
   signal encoded_A : std_logic_vector(35 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: encode PORT MAP (
          A => A,
          encoded_A => encoded_A
        );

 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
		A <= conv_std_logic_vector(199999998, 32);

      -- insert stimulus here 

      wait;
   end process;

END;
