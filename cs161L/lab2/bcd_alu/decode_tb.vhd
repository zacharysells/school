--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   18:59:06 01/27/2014
-- Design Name:   
-- Module Name:   /home/csmajs/zsell001/cs161L/lab2/bcd_alu/decode_tb.vhd
-- Project Name:  bcd_alu
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: decode
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
 
ENTITY decode_tb IS
END decode_tb;
 
ARCHITECTURE behavior OF decode_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT decode
    PORT(
         A : IN  std_logic_vector(31 downto 0);
         B : IN  std_logic_vector(31 downto 0);
         decoded_A : OUT  std_logic_vector(31 downto 0);
         decoded_B : OUT  std_logic_vector(31 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic_vector(31 downto 0) := (others => '0');
   signal B : std_logic_vector(31 downto 0) := (others => '0');

 	--Outputs
   signal decoded_A : std_logic_vector(31 downto 0);
   signal decoded_B : std_logic_vector(31 downto 0);
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: decode PORT MAP (
          A => A,
          B => B,
          decoded_A => decoded_A,
          decoded_B => decoded_B
        );
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      report "Testing decode function";
		A <= conv_std_logic_vector(-1717986919, 32);
		B <= conv_std_logic_vector(67893211, 32);
		wait for 10 ns;
      -- insert stimulus here 

      wait;
   end process;

END;
