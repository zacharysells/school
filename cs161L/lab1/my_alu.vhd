----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:41:00 01/06/2014 
-- Design Name: 
-- Module Name:    my_alu - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use STD.textio.all;                     -- basic I/O
use IEEE.std_logic_textio.all;          -- I/O for logic types

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity my_alu is
	 Generic( NUMBITS : natural := 8);
    Port ( A : in  STD_LOGIC_VECTOR (NUMBITS-1 downto 0);
           B : in  STD_LOGIC_VECTOR (NUMBITS-1 downto 0);
           opcode : in  STD_LOGIC_VECTOR (2 downto 0);
           result : out  STD_LOGIC_VECTOR (NUMBITS-1 downto 0);
           carryout : out  STD_LOGIC;
           overflow : out  STD_LOGIC;
           zero : out  STD_LOGIC);
end my_alu;

architecture Behavioral of my_alu is
signal temp : STD_LOGIC_VECTOR(NUMBITS downto 0) := (others => '0');
signal zero_sig : std_logic_vector(NUMBITS-1 downto 0) := (others => '0');
signal a_sext : std_logic_vector(NUMBITS downto 0);
signal b_sext : std_logic_vector(NUMBITS downto 0);
begin
	
	carryout <= temp(NUMBITS);
	zero <= '1' when (temp(NUMBITS-1 downto 0) = zero_sig) else '0';
	process(A, B, opcode, temp) --sensitivity list
	variable my_line : line;
	begin
		
		case opcode is
			when "000" => --unsigned add
			temp <= std_logic_vector(unsigned('0' & A)  + unsigned('0' & B));
			result <= temp(NUMBITS-1 downto 0);
			overflow <= temp(NUMBITS);
			
			when "001" => --signed add
			
			temp <= std_logic_vector(unsigned('0' & A)  + unsigned('0' & B));
			result <= temp(NUMBITS-1 downto 0);
			if (A(NUMBITS-1) = '0' and B(NUMBITS-1) = '0') then
				overflow <= temp(NUMBITS - 1);
			elsif (A(NUMBITS - 1) = '1' and B(NUMBITS - 1) = '1') then
				overflow <= not(temp(NUMBITS - 1));
			else
				overflow <= '0';
			end if;
			
			when "010" => --unsigned sub
			temp <= std_logic_vector(unsigned('0' & A) + unsigned(std_logic_vector('0' & (unsigned(not(B)) + 1))));
			result <= temp(NUMBITS-1 downto 0);
			overflow <= not(temp(NUMBITS));
			
			when "011" => --signed sub
			temp <= std_logic_vector(unsigned('0' & A) + unsigned(std_logic_vector('0' & (unsigned(not(B)) + 1))));
			result <= temp(NUMBITS-1 downto 0);
			if A(NUMBITS-1) = '0' and B(NUMBITS-1) = '1' then
				overflow <= temp(NUMBITS - 1);
			elsif A(NUMBITS - 1) = '1' and B(NUMBITS - 1) = '0' then
				overflow <= not(temp(NUMBITS - 1));
			else
				overflow <= '0';
			end if;
			
			when "100" => --bitwise AND
			result <= A and B;
			overflow <= '0';
			temp <= zero_sig;
			
			when "101" => --bitwise OR
			result <= A or B;
			overflow <= '0';
			temp <= zero_sig;
			
			when "110" => --bitwise XOR
			result <= A xor B;
			overflow <= '0';
			temp <= zero_sig;
			
			when "111" => --bitwise XOR
			result <= '0' & A(NUMBITS-1 downto 1);
			overflow <= '0';
			temp <= zero_sig;
			
			
			when others => --other
			result <= temp(NUMBITS-1 downto 0);
			
		end case;
	end process;


end Behavioral;

