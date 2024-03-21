library ieee;
use ieee.std_logic_1164.all;

entity decoder_tb is
end decoder_tb;

architecture test of decoder_tb is
    component decoder
        port (
            a, b, c : in bit;
            D0, D1, D2, D3, D4, D5, D6, D7 : out bit
        );
    end component;
    
    signal a, b, c, D0, D1, D2, D3, D4, D5, D6, D7 : bit;
begin
    decoder_inst : decoder port map (
        a => a, b => b, c => c,
        D0 => D0, D1 => D1, D2 => D2, D3 => D3,
        D4 => D4, D5 => D5, D6 => D6, D7 => D7
    );

    process
    begin
        wait for 1 ns;
        a <= '0';
        b <= '0';
        c <= '0';

        wait for 1 ns;
        a <= '0';
        b <= '0';
        c <= '1';

        wait for 1 ns;
        a <= '0';
        b <= '1';
        c <= '0';

        wait for 1 ns;
        a <= '0';
        b <= '1';
        c <= '1';

        wait for 1 ns;
        a <= '1';
        b <= '0';
        c <= '0';

        wait for 1 ns;
        a <= '1';
        b <= '0';
        c <= '1';

        wait for 1 ns;
        a <= '1';
        b <= '1';
        c <= '0';

        wait for 1 ns;
        a <= '1';
        b <= '1';
        c <= '1';

        assert false report "Reached end of test";
        wait;
    end process;
end test;
