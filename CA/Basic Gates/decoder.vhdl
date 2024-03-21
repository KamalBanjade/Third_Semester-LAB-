library ieee;
use ieee.std_logic_1164.all;

entity decoder is 
    port (
        a, b, c : in bit; 
        D0, D1, D2, D3, D4, D5, D6, D7 : out bit 
    );
end decoder;

architecture behave of decoder is
begin
    D0 <= (not a) and (not b) and (not c);
    D1 <= (not a) and (not b) and c;
    D2 <= (not a) and b and (not c); -- corrected line
    D3 <= (not a) and b and c;
    D4 <= a and (not b) and (not c);
    D5 <= a and (not b) and c;
    D6 <= a and b and (not c);
    D7 <= a and b and c;
end behave;
