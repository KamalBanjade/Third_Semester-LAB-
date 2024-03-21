library ieee;
use ieee.std_logic_1164.all;
entity hs_tb is
end hs_tb;

architecture test of hs_tb is
component hs
port
(
	a, b: in bit;
	s, c: out bit
);
end component;
signal a, b, s, c: bit;
begin											
half_subtractor: hs port map
(a=>a, b=>b, s=>s, c=>c);
process begin
	a <= '0';
	b <= '0';
	wait for 1 ns;
	a <= '0';
	b <= '1';
	wait for 1 ns;
	a <= '1';
	b <= '0';
	wait for 1 ns;
	a <= '1';
	b <= '1';
	wait for 1 ns;
	assert false report "Reached end of test";
wait;
end process;
end test;
