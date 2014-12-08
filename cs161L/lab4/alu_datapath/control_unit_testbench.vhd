LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY control_unit_testbench IS
END control_unit_testbench;
 
ARCHITECTURE behavior OF control_unit_testbench IS 
 
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

   constant clk_period : time := 10 ns;
 
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
		wait for clk_period;	

		
		-- Testing R-Type Instructions
		instr_op <= "000000";
		wait for clk_period;
		assert reg_dst 	= '1'		report "R-Type: reg_dst Failed" severity Warning;
		assert alu_src 	= '0'		report "R-Type: alu_src Failed" severity Warning;
		assert mem_to_reg = '0'		report "R-Type: mem_to_reg Failed" severity Warning;
		assert reg_write 	= '1'		report "R-Type: reg_write Failed" severity Warning;
		assert mem_read 	= '0' 	report "R-Type: mem_read Failed" severity Warning;
		assert mem_write 	= '0' 	report "R-Type: mem_write Failed" severity Warning;
		assert branch 		= '0'		report "R-Type: branch Failed" severity Warning;
		assert alu_op 		= "10"	report "R-Type: alu_op Failed" severity Warning;
		
		wait for clk_period;


		-- Testing LW
		instr_op <= "100011";
		wait for clk_period;
		assert reg_dst 	= '0'		report "LW: reg_dst Failed" severity Warning;
		assert alu_src 	= '1'		report "LW: alu_src Failed" severity Warning;
		assert mem_to_reg = '1'		report "LW: mem_to_reg Failed" severity Warning;
		assert reg_write 	= '1'		report "LW: reg_write Failed" severity Warning;
		assert mem_read 	= '1' 	report "LW: mem_read Failed" severity Warning;
		assert mem_write 	= '0' 	report "LW: mem_write Failed" severity Warning;
		assert branch 		= '0'		report "LW: branch Failed" severity Warning;
		assert alu_op 		= "00"	report "LW: alu_op Failed" severity Warning;
		
		wait for clk_period;
		
		
		-- Testing SW
		instr_op <= "101011";
		wait for clk_period;
		assert alu_src 	= '1'		report "SW: alu_src Failed" severity Warning;
		assert reg_write 	= '0'		report "SW: reg_write Failed" severity Warning;
		assert mem_read 	= '0' 	report "SW: mem_read Failed" severity Warning;
		assert mem_write 	= '1' 	report "SW: mem_write Failed" severity Warning;
		assert branch 		= '0'		report "SW: branch Failed" severity Warning;
		assert alu_op 		= "00"	report "SW: alu_op Failed" severity Warning;
		
		wait for clk_period;
		
		
		-- Testing beq
		instr_op <= "000100";
		wait for clk_period;
		assert alu_src 	= '0'		report "BEQ: alu_src Failed" severity Warning;
		assert reg_write 	= '0'		report "BEQ: reg_write Failed" severity Warning;
		assert mem_read 	= '0' 	report "BEQ: mem_read Failed" severity Warning;
		assert mem_write 	= '0' 	report "BEQ: mem_write Failed" severity Warning;
		assert branch 		= '1'		report "BEQ: branch Failed" severity Warning;
		assert alu_op 		= "01"	report "BEQ: alu_op Failed" severity Warning;
		
		wait for clk_period;
	
		-- Testing addi
		instr_op <= "001000";
		wait for clk_period;
		assert reg_dst 	= '0'		report "ADDI-Type: reg_dst Failed" severity Warning;
		assert alu_src 	= '1'		report "ADDI-Type: alu_src Failed" severity Warning;
		assert mem_to_reg = '0'		report "ADDI-Type: mem_to_reg Failed" severity Warning;
		assert reg_write 	= '1'		report "ADDI-Type: reg_write Failed" severity Warning;
		assert mem_read 	= '0' 	report "ADDI-Type: mem_read Failed" severity Warning;
		assert mem_write 	= '0' 	report "ADDI-Type: mem_write Failed" severity Warning;
		assert branch 		= '0'		report "ADDI-Type: branch Failed" severity Warning;
		
		
		wait for clk_period;
		
		
      wait;
   end process;

END;
