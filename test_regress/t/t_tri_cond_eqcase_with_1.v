// DESCRIPTION: Verilator: Verilog Test module
//
// This file ONLY is placed under the Creative Commons Public Domain, for
// any use, without warranty, 2022 by Antmicro Ltd.
// SPDX-License-Identifier: CC0-1.0

module t (/*AUTOARG*/
   // Inputs
   clk
   );
   input clk;
   wire  a;
   assign a = 1 === (clk ? 1 : 1'bz);

   always begin
      if (!a) begin
         $write("*-* All Finished *-*\n");
         $finish;
      end
   end
endmodule
