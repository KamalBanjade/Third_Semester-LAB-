library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity paralleladd is
    port (
        A, B: in STD_LOGIC_VECTOR(3 downto 0);
        S: out STD_LOGIC_VECTOR(3 downto 0);
        Cin: in STD_LOGIC;
        Cout: out STD_LOGIC
    );
end paralleladd;

architecture behave of paralleladd is
begin
    process (A, B, Cin)
        variable t: STD_LOGIC;
    begin
        t := Cin;
        for i in 0 to 3 loop
            S(i) <= A(i) XOR B(i) XOR t;
            t := (A(i) AND B(i)) OR ((t AND A(i)) OR (t AND B(i)));
        end loop;
        Cout <= t;
    end process;
end behave;
