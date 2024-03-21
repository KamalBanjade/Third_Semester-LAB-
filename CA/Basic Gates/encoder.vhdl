library ieee;
use ieee.std_logic_1164.all;

entity Encoder is
    port (
        D0, D1, D2, D3, D4, D5, D6, D7 : in bit;
        a, b, c : out bit
    );
end Encoder;

architecture behave of Encoder is
begin
    a <= D4 or D5 or D6 or D7;
    b <= D7 or D6 or D2 or D3;
    c <= D1 or D3 or D5 or D7;
end behave;
