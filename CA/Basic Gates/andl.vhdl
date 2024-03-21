library ieee;
use ieee.std_logic_1164.all;
entity andl is
  port (
    a, b: in bit;
    o: out bit
  );
end andl;

architecture behave of andl is
begin
  o <= a and b;
end behave;
