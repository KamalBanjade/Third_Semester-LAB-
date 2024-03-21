library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity parallelsub is
    port (
        A, B: in STD_LOGIC_VECTOR(3 downto 0);
        S: out STD_LOGIC_VECTOR(3 downto 0);
		Cin:in STD_LOGIC;
        Cout : out STD_LOGIC
    );
end parallelsub;

architecture behave of parallelsub is
begin
    process (A, B, Cin)
        variable t: STD_LOGIC;
    begin
        t := Cin; 
        for i in 0 to 3 loop
            S(i) <= A(i) XOR (NOT (B(i))) XOR t;
            t := ( A(i) AND NOT (B(i))) OR ( t AND (A(i))) OR (t AND NOT(B(i)));
        end loop;
         Cout<= t;
    end process;
end behave;
