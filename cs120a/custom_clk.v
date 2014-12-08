reg [24:0] d;
wire [24:0] dInc = d[24] ? (24) : (24 - 14152300);
wire [24:0] dN = d + dInc;
always @(posedge sys_clk_i)
begin
  d = dN;
end
wire b_clk = ~d[24];  // clock B tick whenever d[24] is zero
