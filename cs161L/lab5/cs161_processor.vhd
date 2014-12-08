library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.cpu_component_library.all;

entity cs161_processor is
  port (
    clk            : in std_logic;
    rst            : in std_logic;
    
    -- Debug Signals
    prog_count     : out std_logic_vector(31 downto 0);
    instr_opcode   : out std_logic_vector(5 downto 0);
    reg1_addr      : out std_logic_vector(4 downto 0);
    reg1_data      : out std_logic_vector(31 downto 0);
    reg2_addr      : out std_logic_vector(4 downto 0);
    reg2_data      : out std_logic_vector(31 downto 0);
    write_reg_addr : out std_logic_vector(4 downto 0);
    write_reg_data : out std_logic_vector(31 downto 0)
    );
end cs161_processor;

architecture Behavioral of cs161_processor is
	signal mux_to_pc : std_logic_vector(31 downto 0);
	signal pc_to_mem : std_logic_vector(31 downto 0);
	signal instr : std_logic_vector(31 downto 0);
	signal instr_31_dt_26 : std_logic_vector(5 downto 0);
	signal instr_25_dt_21 : std_logic_vector(4 downto 0);
	signal instr_20_dt_16 : std_logic_vector(4 downto 0);
	signal instr_15_dt_11 : std_logic_vector(4 downto 0);
	
	signal instr_5_dt_0 : std_logic_vector(5 downto 0);
	signal sext_sl2_instruction_15_dt_0 : std_logic_vector(31 downto 0);
	signal sext_instruction_15_dt_0 : std_logic_vector(31 downto 0);
	signal pc_plus_4 : std_logic_vector(31 downto 0);
	signal cntrl_memwrite_to_datamemory : std_logic;
	signal alu_result : std_logic_vector(31 downto 0);
	signal reg_readdata2_to_datamemwrite : std_logic_vector(31 downto 0);
	signal datamemory_readaddress_to_datamemory_mux : std_logic_vector(31 downto 0);
	signal cntrl_reg_dst_to_instmux : std_logic;
	signal cntrl_memread_to_datamemory : std_logic;
	signal cntrl_memtoreg_to_datamemory_mux : std_logic;
	signal cntrl_aluop_to_alucontrol : std_logic_vector(1 downto 0);
	signal cntrl_alusrc_to_alumux : std_logic;
	signal cntrl_regwrite_to_cpuregisters : std_logic;
	
	
	signal instrmux_to_cpuregisters_writeregister : std_logic_vector(4 downto 0);
	
	signal alucontrol_to_alucontrolin : std_logic_vector(3 downto 0);
	
	signal cpuregisters_readdata1_to_aluchannelain : std_logic_vector(31 downto 0);
	signal alumux_to_aluchannelbin : std_logic_vector(31 downto 0);
	signal cpuregisters_readdata2_to_alumux : std_logic_vector(31 downto 0);
	
	signal alu_zero_sig : std_logic;
	signal control_br : std_logic;
	
	
	signal datamemory_mux_to_cpuregisters_writedata : std_logic_vector(31 downto 0);
	signal datamemory_readdata_to_datamemory_mux : std_logic_vector(31 downto 0);
	
	
begin
	
	instr_31_dt_26 <= instr(31 downto 26);
	instr_25_dt_21 <= instr(25 downto 21);
	instr_20_dt_16 <= instr(20 downto 16);
	instr_15_dt_11 <= instr(15 downto 11);
	
	instr_5_dt_0 <= instr(5 downto 0);
	pc_plus_4 <= std_logic_vector(unsigned(pc_to_mem) + to_unsigned(4, 32));
	sext_instruction_15_dt_0 <= std_logic_vector(resize(signed(instr(15 downto 0)), 32));
	sext_sl2_instruction_15_dt_0 <= std_logic_vector(unsigned(sext_instruction_15_dt_0) sll 2);
	

	
	PC : generic_register generic map(SIZE=> 32)
											port map(clk => clk, 
											rst => rst,
											write_en => '1',
											data_in=>mux_to_pc,
											data_out => pc_to_mem);
											
	pc_mux : mux_2_1 generic map(SIZE => 32)		
									  port map(select_in => (control_br OR alu_zero_sig),
									  data_0_in => pc_plus_4,
									  data_1_in => std_logic_vector(unsigned(pc_plus_4) + unsigned(sext_sl2_instruction_15_dt_0)),
									  data_out => mux_to_pc);
									  
	instr_mux : mux_2_1 generic map(SIZE => 5)
										 port map(select_in => cntrl_reg_dst_to_instmux,
													 data_0_in => instr_20_dt_16,
													 data_1_in => instr_15_dt_11,
													 data_out => instrmux_to_cpuregisters_writeregister);
									  
	alu_mux : mux_2_1 generic map(SIZE => 32)
									  port map(select_in => cntrl_alusrc_to_alumux,
												  data_0_in => cpuregisters_readdata2_to_alumux,
												  data_1_in => sext_instruction_15_dt_0,
												  data_out => alumux_to_aluchannelbin);
	
   datamemory_mux : mux_2_1 generic map(SIZE => 32)
										port map(select_in => cntrl_memtoreg_to_datamemory_mux,
													data_0_in => alu_result,
													data_1_in => datamemory_readdata_to_datamemory_mux,
													data_out => datamemory_mux_to_cpuregisters_writedata);
	
	
	instruction_memory : memory port map(clk => clk,
													 rst => rst,
													 instr_read_address => pc_to_mem(9 downto 2),
													 instr_instruction => instr,
													 data_mem_write => cntrl_memwrite_to_datamemory,
													 data_address => alu_result(7 downto 0),
													 data_write_data => reg_readdata2_to_datamemwrite,
													 data_read_data => datamemory_readaddress_to_datamemory_mux);
													 
	cntrl_unit : control_unit port map(instr_op => instr_31_dt_26,
												  reg_dst => cntrl_reg_dst_to_instmux,
												  branch => control_br,
												  mem_read => cntrl_memread_to_datamemory,
												  mem_to_reg => cntrl_memtoreg_to_datamemory_mux,
												  alu_op => cntrl_aluop_to_alucontrol,
												  mem_write => cntrl_memwrite_to_datamemory,
												  alu_src => cntrl_alusrc_to_alumux,
												  reg_write => cntrl_regwrite_to_cpuregisters);
												  
	alu_cntrl : alu_control port map(alu_op => cntrl_aluop_to_alucontrol,
												  instruction_5_0 => instr_5_dt_0,
												  alu_out => alucontrol_to_alucontrolin);
												  
	alu_unit : alu port map(alu_control_in => alucontrol_to_alucontrolin,
									channel_a_in => cpuregisters_readdata1_to_aluchannelain,
									channel_b_in => alumux_to_aluchannelbin,
									zero_out => alu_zero_sig,
									alu_result_out => alu_result);
												  
												  
	cpu_regs : cpu_registers port map(clk => clk,
												 rst => rst,
												 reg_write => cntrl_regwrite_to_cpuregisters,
												 read_register_1 => instr_25_dt_21,
												 read_register_2 => instr_20_dt_16,
												 write_register => instrmux_to_cpuregisters_writeregister,
												 write_data => datamemory_mux_to_cpuregisters_writedata,
												 read_data_1 => cpuregisters_readdata1_to_aluchannelain,
												 read_data_2 => cpuregisters_readdata2_to_alumux);
												 
												  
	prog_count <= pc_to_mem;
	instr_opcode <= instr_31_dt_26;
	reg1_addr <= instr_25_dt_21;
   reg1_data <= cpuregisters_readdata1_to_aluchannelain;
   reg2_addr <= instr_20_dt_16;
   reg2_data <= cpuregisters_readdata2_to_alumux;
   write_reg_addr <= instrmux_to_cpuregisters_writeregister;
   write_reg_data <= datamemory_mux_to_cpuregisters_writedata;				  


end Behavioral;

