library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity paralleladd_tb is
end paralleladd_tb;

architecture test of paralleladd_tb is
    component paralleladd
        Port (
            A : in STD_LOGIC_VECTOR (3 downto 0);
            B : in STD_LOGIC_VECTOR (3 downto 0);
            S : out STD_LOGIC_VECTOR (3 downto 0);
            Cin : in STD_LOGIC;
            Cout : out STD_LOGIC
        );
    end component;

    -- Input signals
    signal A, B: STD_LOGIC_VECTOR (3 downto 0) := (others =>'0');
    signal Cin: STD_LOGIC;

    -- Output signals
    signal S: STD_LOGIC_VECTOR (3 downto 0) := (others => '0');
    signal Cout: STD_LOGIC;
	begin
    -- Instantiate the Unit Under Test (UUT)
    UUT: paralleladd port map (
        A => A,
        B => B,
        S => S,
        Cin => Cin,
        Cout => Cout
    );
	 process
    begin
        A <= "0101";
        B <= "0100";
        Cin <= '0';
        wait for 20 ns;

        A <= "1111";
        B <= "0001";
        Cin <= '1';
        wait for 20 ns;

        A<="1010";
		B<="1001";
		Cin<='1';
		 wait for 20 ns;

        wait;
    end process;

end test;