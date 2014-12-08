
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;


entity CAM_Cell is
    Port ( clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           we : in  STD_LOGIC;
           cell_search_bit : in  STD_LOGIC;
           cell_dont_care_bit : in  STD_LOGIC;
			  cell_match_bit_in : in  STD_LOGIC ;
           cell_match_bit_out : out  STD_LOGIC);
end CAM_Cell;

architecture Ternary_at_Input_Cell of CAM_Cell is

begin



end Ternary_at_Input_Cell ;



architecture Binary_Input_Cell of CAM_CELL is

begin



end Binary_Input_Cell;






