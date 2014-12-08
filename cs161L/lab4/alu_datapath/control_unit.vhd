library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.cpu_constant_library.all;

entity control_unit is
  port (
    instr_op          : in std_logic_vector(5 downto 0);
    reg_dst           : out std_logic;
    branch            : out std_logic;
    mem_read          : out std_logic;
    mem_to_reg        : out std_logic;
    alu_op            : out std_logic_vector(1 downto 0);
    mem_write         : out std_logic;
    alu_src           : out std_logic;
    reg_write         : out std_logic
    );
end control_unit;

architecture Behavioral of control_unit is
begin
	reg_dst <= not(instr_op(0)) AND not(instr_op(1)) AND not(instr_op(2)) AND not(instr_op(3)) AND not(instr_op(4)) AND not(instr_op(5));
	
	branch <= not(instr_op(0)) AND not(instr_op(1)) AND (instr_op(2)) AND not(instr_op(3)) AND not(instr_op(4)) AND not(instr_op(5));
	
	mem_read <= (instr_op(0)) AND (instr_op(1)) AND not(instr_op(2)) AND not(instr_op(3)) AND not(instr_op(4)) AND (instr_op(5));
	
	mem_to_reg <= (instr_op(0)) AND (instr_op(1)) AND not(instr_op(2)) AND not(instr_op(3)) AND not(instr_op(4)) AND (instr_op(5));
	
	alu_op(0) <= not(instr_op(0)) AND not(instr_op(1)) AND (instr_op(2)) AND not(instr_op(3)) AND not(instr_op(4)) AND not(instr_op(5));

	alu_op(1) <= not(instr_op(0)) AND not(instr_op(1)) AND not(instr_op(2)) AND not(instr_op(3)) AND not(instr_op(4)) AND not(instr_op(5));

	mem_write <= (instr_op(0)) AND (instr_op(1)) AND not(instr_op(2)) AND (instr_op(3)) AND not(instr_op(4)) AND (instr_op(5));

	alu_src <= ((instr_op(0)) AND (instr_op(1)) AND not(instr_op(2)) AND not(instr_op(3)) AND not(instr_op(4)) AND (instr_op(5))) OR
					((instr_op(0)) AND (instr_op(1)) AND not(instr_op(2)) AND (instr_op(3)) AND not(instr_op(4)) AND (instr_op(5)));

	reg_write <= (not(instr_op(0)) AND not(instr_op(1)) AND not(instr_op(2)) AND not(instr_op(3)) AND not(instr_op(4)) AND not(instr_op(5))) OR
					((instr_op(0)) AND (instr_op(1)) AND not(instr_op(2)) AND not(instr_op(3)) AND not(instr_op(4)) AND (instr_op(5)));
end Behavioral;
