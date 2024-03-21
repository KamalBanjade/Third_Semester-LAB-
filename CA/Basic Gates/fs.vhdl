library ieee;
use ieee.std_logic_1164.all;
entity fs is
port
(
	a, b, c: in bit;
	d, br: out bit
);
end fs;

architecture behave of fs is
begin
d <= a xor b xor c;
br <= (not a and b) or (not a and c) or (b and c);
end behave;