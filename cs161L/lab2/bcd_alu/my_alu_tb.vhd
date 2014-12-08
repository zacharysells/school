--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   19:43:47 02/04/2014
-- Design Name:   
-- Module Name:   /home/zacharysells/Documents/cs161L/lab2/bcd_alu/my_alu_tb.vhd
-- Project Name:  bcd_alu
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: my_alu
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
 
ENTITY my_alu_tb IS
END my_alu_tb;
 
ARCHITECTURE behavior OF my_alu_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT my_alu
    PORT(
         A : IN  std_logic_vector(31 downto 0);
         B : IN  std_logic_vector(31 downto 0);
         opcode : IN  std_logic_vector(3 downto 0);
         result : OUT  std_logic_vector(35 downto 0);
         carryout : OUT  std_logic;
         overflow : OUT  std_logic;
         zero : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic_vector(31 downto 0) := (others => '0');
   signal B : std_logic_vector(31 downto 0) := (others => '0');
   signal opcode : std_logic_vector(3 downto 0) := (others => '0');

 	--Outputs
   signal result : std_logic_vector(35 downto 0);
   signal carryout : std_logic;
   signal overflow : std_logic;
   signal zero : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: my_alu PORT MAP (
          A => A,
          B => B,
          opcode => opcode,
          result => result,
          carryout => carryout,
          overflow => overflow,
          zero => zero
        );
 

   -- Stimulus process
   stim_proc: process
	variable my_line : line;
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
        -- --------------------------------------------------------------------------------
        -- --------------------------------------------------------------------------------
        -- Testing Unsigned Add
        -- --------------------------------------------------------------------------------
        -- --------------------------------------------------------------------------------
        report "Testing Unsigned Add";
        opcode <= "1000";
        
            -- Test 1
				A <= conv_std_logic_vector(0, 32);
				B <= conv_std_logic_vector(0, 32);
            
            wait for 10 ns;
            assert result = conv_std_logic_vector(0, 36)     report "Test_1: result incorrect"     severity Warning;
            assert carryout = '0'                                 report "Test_1: carryout incorrect"    severity Warning;
            assert overflow = '0'                                 report "Test_1: overflow incorrect"    severity Warning;
            assert zero = '1'                                        report "Test_1: zero incorrect"        severity Warning;
			
			
				-- Test 2
            A <= conv_std_logic_vector(74565, 32); --12,345 + 6,789 = 19134
            B <= conv_std_logic_vector(26505, 32); 

            wait for 10 ns;
            assert result = conv_std_logic_vector(102708, 36)     report "Test_2: result incorrect"     severity Warning;
            assert carryout = '0'                                 report "Test_2: carryout incorrect"    severity Warning;
            assert overflow = '0'                                 report "Test_2: overflow incorrect"    severity Warning;
            assert zero = '0'                                        report "Test_2: zero incorrect"        severity Warning;
      
		  -- --------------------------------------------------------------------------------
        -- --------------------------------------------------------------------------------
        -- Testing Unsigned Sub
        -- --------------------------------------------------------------------------------
        -- --------------------------------------------------------------------------------
        report "Testing Unsigned Sub";
        opcode <= "1001";
        
            -- Test 1
				A <= "00000000000000000000000000010010";
				B <= "00000000000000000000000000010010";
            
            wait for 10 ns;
            assert result = conv_std_logic_vector(0, 36)		     report "Test_1: result incorrect"     severity Warning;
            assert carryout = '1'                                 report "Test_1: carryout incorrect"    severity Warning;
            assert overflow = '0'                                 report "Test_1: overflow incorrect"    severity Warning;
            assert zero = '1'                                        report "Test_1: zero incorrect"        severity Warning;
			
			
				-- Test 2
            A <= conv_std_logic_vector(74565, 32); --12,345 - 6,789 = 5556
				B <= conv_std_logic_vector(26505, 32);

            wait for 10 ns;
            assert result = conv_std_logic_vector(21846, 36)     report "Test_2: result incorrect"     severity Warning;
            assert carryout = '1'                                 report "Test_2: carryout incorrect"    severity Warning;
            assert overflow = '0'                                 report "Test_2: overflow incorrect"    severity Warning;
            assert zero = '0'                                        report "Test_2: zero incorrect"        severity Warning;
				
				
				
		  -- --------------------------------------------------------------------------------
        -- --------------------------------------------------------------------------------
        -- Testing Signed Add
        -- --------------------------------------------------------------------------------
        -- --------------------------------------------------------------------------------
        report "Testing Signed Add";
        opcode <= "1100";
        
            -- Test 1
				A <= conv_std_logic_vector(0, 32);
				B <= conv_std_logic_vector(0, 32);
            
            wait for 10 ns;
            assert result = conv_std_logic_vector(0, 36)     report "Test_1: result incorrect"     severity Warning;
            assert carryout = '0'                                 report "Test_1: carryout incorrect"    severity Warning;
            assert overflow = '0'                                 report "Test_1: overflow incorrect"    severity Warning;
            assert zero = '1'                                        report "Test_1: zero incorrect"        severity Warning;
			
			
				-- Test 2
            A <= conv_std_logic_vector(55, 32); --37 + (-12) = 25
				B <= "00010000000000000000000000010010";

            wait for 10 ns;
            assert result = conv_std_logic_vector(37, 36)     report "Test_2: result incorrect"     severity Warning;
            assert carryout = '1'                                 report "Test_2: carryout incorrect"    severity Warning;
            assert overflow = '0'                                 report "Test_2: overflow incorrect"    severity Warning;
            assert zero = '0'                                        report "Test_2: zero incorrect"        severity Warning;
				
				-- Test 3
            A <= "00000000000000000000000000010000"; --10 + (-112) = -102
				B <= "00010000000000000000000100010010";

            wait for 10 ns;
            assert result = "000100000000000000000000000100000010"    report "Test_3: result incorrect"     severity Warning;
            assert carryout = '0'                                 report "Test_3: carryout incorrect"    severity Warning;
            assert overflow = '0'                                 report "Test_3: overflow incorrect"    severity Warning;
            assert zero = '0'                                        report "Test_3: zero incorrect"        severity Warning;
				
				
		  -- --------------------------------------------------------------------------------
        -- --------------------------------------------------------------------------------
        -- Testing Signed Sub
        -- --------------------------------------------------------------------------------
        -- --------------------------------------------------------------------------------
        report "Testing Signed Sub";
        opcode <= "1101";
        
            -- Test 1
				A <= conv_std_logic_vector(0, 32);
				B <= conv_std_logic_vector(0, 32);
            
            wait for 10 ns;
            assert result = conv_std_logic_vector(0, 36)     report "Test_1: result incorrect"     severity Warning;
            assert carryout = '0'                                 report "Test_1: carryout incorrect"    severity Warning;
            assert overflow = '0'                                 report "Test_1: overflow incorrect"    severity Warning;
            assert zero = '1'                                        report "Test_1: zero incorrect"        severity Warning;
			
			
				-- Test 2
            A <= "00010000000000000000000000000010";
				B <= "00010000000000000000000000010000";

            wait for 10 ns;
            assert result = "000000000000000000000000000000001000"     report "Test_2: result incorrect"     severity Warning;
            assert carryout = '1'                                 report "Test_2: carryout incorrect"    severity Warning;
            assert overflow = '0'                                 report "Test_2: overflow incorrect"    severity Warning;
            assert zero = '0'                                        report "Test_2: zero incorrect"        severity Warning;
				
				
				-- Test 3
            A <= "00010000000000000000000100010111"; -- -117 -(368) = -485
				B <= "00000000000000000000001101101000";

            wait for 10 ns;
            assert result = "000100000000000000000000010010000101"     report "Test_3: result incorrect"     severity Warning;
            assert carryout = '1'                                 report "Test_3: carryout incorrect"    severity Warning;
            assert overflow = '0'                                 report "Test_3: overflow incorrect"    severity Warning;
            assert zero = '0'                                        report "Test_3: zero incorrect"        severity Warning;
		
		wait;
   end process;

END;
--Zachary Sells
--Feb 9, 2014
