library ieee;
use ieee.std_logic_1164.all;
entity hs is
port
(
	a, b: in bit;
	s, c: out bit
);
end hs;

architecture behave of hs is
begin
s <= a xor b;
c <= not a and b;
end behave;