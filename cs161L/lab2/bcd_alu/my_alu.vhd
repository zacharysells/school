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
	 Generic( NUMBITS : natural := 32);
    Port ( A : in  STD_LOGIC_VECTOR (NUMBITS-1 downto 0);
           B : in  STD_LOGIC_VECTOR (NUMBITS-1 downto 0);
           opcode : in  STD_LOGIC_VECTOR (3 downto 0);
           result : out  STD_LOGIC_VECTOR (NUMBITS+4-1 downto 0);
           carryout : out  STD_LOGIC;
           overflow : out  STD_LOGIC;
           zero : out  STD_LOGIC);
			  
		function decode(bcd_in : std_logic_vector(31 downto 0)) return std_logic_vector is
		variable temp0 : integer := 0;
		variable temp1 : integer := 0;
		variable temp2 : integer := 0;
		variable temp3 : integer := 0;
		variable temp4 : integer := 0;
		variable temp5 : integer := 0;
		variable temp6 : integer := 0;
		variable temp7 : integer := 0;
		variable mline : line;
		variable tot : std_logic_vector(NUMBITS+4-1 downto 0);
		begin
			temp0 := to_integer(unsigned(bcd_in(3 downto 0)));
			temp1 := to_integer(unsigned(bcd_in(7 downto 4)));
			temp2 := to_integer(unsigned(bcd_in(11 downto 8)));
			temp3 := to_integer(unsigned(bcd_in(15 downto 12)));
			temp4 := to_integer(unsigned(bcd_in(19 downto 16)));
			temp5 := to_integer(unsigned(bcd_in(23 downto 20)));
			temp6 := to_integer(unsigned(bcd_in(27 downto 24)));
			temp7 := to_integer(unsigned(bcd_in(31 downto 28)));
		
			tot := std_logic_vector(to_unsigned(temp0*10**0, 36) + to_unsigned(temp1*10**1, 36) + to_unsigned(temp2*10**2,  36)
											+to_unsigned(temp3*10**3, 36) + to_unsigned(temp4*10**4, 36) + to_unsigned(temp5*10**5, 36)
											+to_unsigned(temp6*10**6, 36) + to_unsigned(temp7*10**7, 36));
			return tot;

end decode;


		function decode_signed(bcd_in : std_logic_vector(27 downto 0)) return std_logic_vector is
		variable temp0 : integer := 0;
		variable temp1 : integer := 0;
		variable temp2 : integer := 0;
		variable temp3 : integer := 0;
		variable temp4 : integer := 0;
		variable temp5 : integer := 0;
		variable temp6 : integer := 0;
		variable mline : line;
		variable tot : std_logic_vector(NUMBITS-1 downto 0);
		begin
			temp0 := to_integer(unsigned(bcd_in(3 downto 0)));
			temp1 := to_integer(unsigned(bcd_in(7 downto 4)));
			temp2 := to_integer(unsigned(bcd_in(11 downto 8)));
			temp3 := to_integer(unsigned(bcd_in(15 downto 12)));
			temp4 := to_integer(unsigned(bcd_in(19 downto 16)));
			temp5 := to_integer(unsigned(bcd_in(23 downto 20)));
			temp6 := to_integer(unsigned(bcd_in(27 downto 24)));
		
			tot := std_logic_vector(to_unsigned(temp0*10**0, 32) + to_unsigned(temp1*10**1, 32) + to_unsigned(temp2*10**2,  32)
											+to_unsigned(temp3*10**3, 32) + to_unsigned(temp4*10**4, 32) + to_unsigned(temp5*10**5, 32)
											+to_unsigned(temp6*10**6, 32));
			
			return tot;

end decode_signed;
			  
			  
		function encode(bin : std_logic_vector(35 downto 0)) return std_logic_vector is
			variable bcd : std_logic_vector(35 downto 0) := (others => '0');
			variable bint : std_logic_vector(35 downto 0) := bin;
			variable my_line : line;
			begin
			
			for i in 0 to 35 loop  -- repeating 36 times.
				bcd(35 downto 1) := bcd(34 downto 0);  --shifting the bits.
				bcd(0) := bint(35);
				bint(35 downto 1) := bint(34 downto 0);
				bint(0) :='0';

				if(i < 35 and bcd(3 downto 0) > "0100") then --add 3 if BCD digit is greater than 4.
				bcd(3 downto 0) := std_logic_vector(unsigned(bcd(3 downto 0)) + "0011");
				end if;
					
				if(i < 35 and bcd(7 downto 4) > "0100") then --add 3 if BCD digit is greater than 4.
				bcd(7 downto 4) := std_logic_vector(unsigned(bcd(7 downto 4)) + "0011");
				end if;
				
				if(i < 35 and bcd(11 downto 8) > "0100") then  --add 3 if BCD digit is greater than 4.
				bcd(11 downto 8) := std_logic_vector(unsigned(bcd(11 downto 8)) + "0011");
				end if;
					
				if(i < 35 and bcd(15 downto 12) > "0100") then --add 3 if BCD digit is greater than 4.
				bcd(15 downto 12) := std_logic_vector(unsigned(bcd(15 downto 12)) + "0011");
				end if;

				if(i < 35 and bcd(19 downto 16) > "0100") then --add 3 if BCD digit is greater than 4.
				bcd(19 downto 16) := std_logic_vector(unsigned(bcd(19 downto 16)) + "0011");
				end if;

				if(i < 35 and bcd(23 downto 20) > "0100") then  --add 3 if BCD digit is greater than 4.
				bcd(23 downto 20) := std_logic_vector(unsigned(bcd(23 downto 20)) + "0011");
				end if;
					
				if(i < 35 and bcd(27 downto 24) > "0100") then --add 3 if BCD digit is greater than 4.
				bcd(27 downto 24) := std_logic_vector(unsigned(bcd(27 downto 24)) + "0011");
				end if;

				if(i < 35 and bcd(31 downto 28) > "0100") then --add 3 if BCD digit is greater than 4.
				bcd(31 downto 28) := std_logic_vector(unsigned(bcd(31 downto 28)) + "0011");
				end if;
				
				if(i < 35 and bcd(35 downto 32) > "0100") then --add 3 if BCD digit is greater than 4.
				bcd(35 downto 32) := std_logic_vector(unsigned(bcd(35 downto 32)) + "0011");
				end if;
					
			end loop;
		return bcd(35 downto 0);
end encode;			  
			  
end my_alu;

architecture Behavioral of my_alu is
signal temp : STD_LOGIC_VECTOR(NUMBITS+4 downto 0) := (others => '0');
--variable zero_sig : std_logic_vector(NUMBITS+4-1 downto 0) := (others => '0');

begin
	
	--a_bin <= "000000000000000000000000000011011101";
	--b_bin <= "000000000000000000000000001001000010";

	process(A,B , opcode, temp) --sensitivity list
	variable a_bin : std_logic_vector(NUMBITS+4-1 downto 0);
	variable b_bin : std_logic_vector(NUMBITS+4-1 downto 0);
	variable temp2 : STD_LOGIC_VECTOR(NUMBITS+4-1 downto 0) := (others => '0');
	variable zero_sig : std_logic_vector(NUMBITS+4-1 downto 0) := (others => '0');
	variable my_line : line;
	begin
--	write(my_line, "a_bin: ");
--	write(my_line, a_bin);
--	writeline(output, my_line);
--	write(my_line, "b_bin: ");
--	write(my_line, b_bin);
--	writeline(output, my_line);
	case opcode is
			when "1000" => --unsigned add
			a_bin := decode(A);
			b_bin := decode(B);
			temp <= std_logic_vector(unsigned('0' & a_bin)  + unsigned('0' & b_bin));
			result <= encode(temp(NUMBITS+4-1 downto 0));
			overflow <= temp(NUMBITS+4);
			
			when "1100" => --signed add
			a_bin := "0000" & decode_signed(A(27 downto 0));
			b_bin := "0000" & decode_signed(B(27 downto 0));
			if(to_integer(unsigned(A(NUMBITS-1 downto 28))) /= 0) then
				a_bin := std_logic_vector(unsigned(not(a_bin)) + 1);
			end if;
			if(to_integer(unsigned(B(NUMBITS-1 downto 28))) /= 0) then 
				b_bin := std_logic_vector(unsigned(not(b_bin)) + 1);
			end if;
			
			temp <= std_logic_vector(unsigned('0' & a_bin)  + unsigned('0' & b_bin));

			if (a_bin(NUMBITS+4-1) = '0' and b_bin(NUMBITS+4-1) = '0') then
				overflow <= temp(NUMBITS+4);
			elsif (a_bin(NUMBITS+4 - 1) = '1' and b_bin(NUMBITS+4 - 1) = '1') then
				overflow <= not(temp(NUMBITS+4));
			else
				overflow <= '0';
			end if;
			
			
			when "1001" => --unsigned sub
			a_bin := decode(A);
			b_bin := decode(B);
			b_bin := std_logic_vector(unsigned(not(b_bin)) + 1);
			temp <= std_logic_vector(unsigned('0' & a_bin)  + unsigned('0' & b_bin));
			overflow <= not(temp(NUMBITS+4));
			
			
			when "1101" => --signed sub
			a_bin := "0000" & decode_signed(A(27 downto 0));
			b_bin := "0000" & decode_signed(B(27 downto 0));
			if(to_integer(unsigned(A(NUMBITS-1 downto 28))) /= 0) then
				a_bin := std_logic_vector(unsigned(not(a_bin)) + 1);
			end if;
			if(to_integer(unsigned(B(NUMBITS-1 downto 28))) /= 0) then 
				b_bin := std_logic_vector(unsigned(not(b_bin)) + 1);
			end if;
			
			b_bin := std_logic_vector(unsigned(not(b_bin)) + 1);
			temp <= std_logic_vector(unsigned('0' & a_bin)  + unsigned('0' & b_bin));
			if a_bin(NUMBITS+4-1) = '0' and b_bin(NUMBITS+4-1) = '1' then
				overflow <= temp(NUMBITS+4);
			elsif a_bin(NUMBITS+4 - 1) = '1' and b_bin(NUMBITS+4 - 1) = '0' then
				overflow <= not(temp(NUMBITS+4));
			else
				overflow <= '0';
			end if;
			
			when others => --other
			result <= encode(temp(NUMBITS+4-1 downto 0));
			
		end case;
		
		if(temp(NUMBITS+4-1) = '0') then
			temp2 := encode(temp(NUMBITS+4-1 downto 0));
			result <= temp2;
		else
			temp2 := not(temp(NUMBITS+4-1 downto 0));
			temp2 := std_logic_vector(unsigned(temp2) + 1);
			temp2 := encode(temp2);
			temp2(NUMBITS+4-1 downto 32) := "0001";
			result <= temp2;
		end if;
		carryout <= temp(NUMBITS+4);
		if(to_integer(unsigned(temp2)) = 0) then
			zero <= '1';
		else
			zero <= '0';
		end if;
	end process;


end Behavioral;

--Zachary Sells
--Feb 9, 2014

