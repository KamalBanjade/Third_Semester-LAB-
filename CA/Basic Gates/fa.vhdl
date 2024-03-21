library ieee;
use ieee.std_logic_1164.all;
entity fa is
port
(
	a, b, c: in bit;
	s, cr: out bit
);
end fa;

architecture behave of fa is
begin
s <= a xor b xor c;
cr <= (a and b) or (b and c) or (a and c);
end behave;