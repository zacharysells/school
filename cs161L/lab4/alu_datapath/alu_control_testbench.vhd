LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY alu_control_testbench IS
END alu_control_testbench;
 
ARCHITECTURE behavior OF alu_control_testbench IS 

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
 
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: alu_control PORT MAP (
          alu_op => alu_op,
          instruction_5_0 => instruction_5_0,
          alu_out => alu_out
        );

   -- Stimulus process
   stim_proc: process
   begin		
      wait for clk_period*10;
		
		instruction_5_0 <= "XXXXXX";
		
		-- Test Load/Store Word
		alu_op	<= "00";
		wait for clk_period;
		assert alu_out = "0010"	report "LW/SW Failed" severity Warning;
		wait for clk_period;
		
		
		-- Test Branch Equal To
      alu_op	<= "01";
		wait for clk_period;
		assert alu_out = "0110"	report "BEQ Failed" severity Warning;
		wait for clk_period;
		
		
		-- Test the different R-type Instructions
		-- ADD
		alu_op	<= "10";
		instruction_5_0 <= "100000";
		wait for clk_period;
		assert alu_out = "0010"	report "ADD Failed" severity Warning;
		wait for clk_period;
		
		-- SUBTRACT
		alu_op	<= "10";
		instruction_5_0 <= "100010";
		wait for clk_period;
		assert alu_out = "0110"	report "SUBTRACT Failed" severity Warning;
		wait for clk_period;
		
		-- AND
		alu_op	<= "10";
		instruction_5_0 <= "100100";
		wait for clk_period;
		assert alu_out = "0000"	report "AND Failed" severity Warning;
		wait for clk_period;
		
		-- OR
		alu_op	<= "10";
		instruction_5_0 <= "100101";
		wait for clk_period;
		assert alu_out = "0001"	report "OR Failed" severity Warning;
		wait for clk_period;
		
		-- NOR
		alu_op	<= "10";
		instruction_5_0 <= "100111";
		wait for clk_period;
		assert alu_out = "1100"	report "NOR Failed" severity Warning;
		wait for clk_period;
		
		-- SET ON LESS THAN
		alu_op	<= "10";
		instruction_5_0 <= "101010";
		wait for clk_period;
		assert alu_out = "0111"	report "SLT Failed" severity Warning;
		wait for clk_period;
		
		
		wait;
   end process;

END;
