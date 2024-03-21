library ieee;
use ieee.std_logic_1164.all;
entity ha is
port
(
	a, b: in bit;
	s, c: out bit
);
end ha;

architecture behave of ha is
begin
s <= a xor b;
c <= a and b;
end behave;