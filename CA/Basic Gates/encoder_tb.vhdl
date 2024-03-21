
library ieee;
use ieee.std_logic_1164.all;

entity Encoder_tb is
end Encoder_tb;

architecture test of Encoder_tb is
    component Encoder
        port (
            D0, D1, D2, D3, D4, D5, D6, D7 : in bit;
            a, b, c : out bit
        );
    end component;

    signal a, b, c, D0, D1, D2, D3, D4, D5, D6, D7 : bit;
begin
    encoder_inst : Encoder port map (
        D0 => D0, D1 => D1, D2 => D2, D3 => D3,
        D4 => D4, D5 => D5, D6 => D6, D7 => D7,
        a => a, b => b, c => c
    );

    process begin
        D0 <= '1';
        D1 <= '0';
        D2 <= '0';
        D3 <= '0';
        D4 <= '0';
        D5 <= '0';
        D6 <= '0';
        D7 <= '0';
        wait for 1 ns;

        D0 <= '0';
        D1 <= '1';
        D2 <= '0';
        D3 <= '0';
        D4 <= '0';
        D5 <= '0';
        D6 <= '0';
        D7 <= '0';
        wait for 1 ns;

        D0 <= '0';
        D1 <= '0';
        D2 <= '1';
        D3 <= '0';
        D4 <= '0';
        D5 <= '0';
        D6 <= '0';
        D7 <= '0';
        wait for 1 ns;

        D0 <= '0';
        D1 <= '0';
        D2 <= '0';
        D3 <= '1';
        D4 <= '0';
        D5 <= '0';
        D6 <= '0';
        D7 <= '0';
        wait for 1 ns;

        D0 <= '0';
        D1 <= '0';
        D2 <= '0';
        D3 <= '0';
        D4 <= '1';
        D5 <= '0';
        D6 <= '0';
        D7 <= '0';
        wait for 1 ns;

        D0 <= '0';
        D1 <= '0';
        D2 <= '0';
        D3 <= '0';
        D4 <= '0';
        D5 <= '1';
        D6 <= '0';
        D7 <= '0';
        wait for 1 ns;

        D0 <= '0';
        D1 <= '0';
        D2 <= '0';
        D3 <= '0';
        D4 <= '0';
        D5 <= '0';
        D6 <= '1';
        D7 <= '0';
        wait for 1 ns;

        D0 <= '0';
        D1 <= '0';
        D2 <= '0';
        D3 <= '0';
        D4 <= '0';
        D5 <= '0';
        D6 <= '0';
        D7 <= '1';
        wait for 1 ns;

        assert false report "Reached end of test";
        wait;
    end process;
end test;