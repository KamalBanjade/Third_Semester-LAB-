library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity parallelsub_tb is
end parallelsub_tb;

architecture test of parallelsub_tb is
    component parallelsub
        Port (
            A : in STD_LOGIC_VECTOR (3 downto 0);
            B : in STD_LOGIC_VECTOR (3 downto 0);
			S:out STD_LOGIC_VECTOR(3 downto 0);
            Cin : in STD_LOGIC ;
            Cout : out STD_LOGIC
        );
    end component;

    signal A, B: STD_LOGIC_VECTOR (3 downto 0) := (others =>'0');
	signal Cin: STD_LOGIC:='1';
	 signal S: STD_LOGIC_VECTOR (3 downto 0) := (others =>'0');
    signal Cout: STD_LOGIC;
begin
    UUT: parallelsub port map (
        A => A,
        B => B,
		S=>S,
        Cin => Cin,
        Cout => Cout
    );

    -- Stimulus process
    stimulus_process: process
    begin
        A <= "0101";
        B <= "0100";
        wait for 20 ns;

        A <= "1111";
        B <= "0001";
        wait for 20 ns;

        A <= "1010";
        B <= "1001";
        wait for 20 ns;

        wait; -- Wait forever
    end process stimulus_process;

end test;
