# Thuật toán truy hồi
Đây là bài toán tìm chữ số cuối khác 0 của n!  
CHữ số cuối khác 0 của n < 10   
  
D(0) = 1, D(1) = 1, D(2) = 2, D(3) = 6, D(4) = 4, D(5) = 2,
D(6) = 2, D(7) = 4, D(8) = 2, D(9) = 8.//

-If chữ số thứ 10 (hoặc chữ số cuối thứ hai) của n là lẻ 
    D(n) = 4 * D(floor(n/5)) * D(chữ số đơn vị của n) 
\\
-If chữ số thứ 10 (hoặc chữ số cuối thứ hai) của n là chẵn \\
    D(n) = 6 * D(floor(n/5)) * D(Chữ số đơn vị của n) \\
\\
Ví dụ 1: n = 27 [Chữ số thứ 2 từ dưới lên là chẵn]: \\
D(27) = 6 * D(floor(27/5)) * D(7) \\
      = 6 * D(5) * D(7) \\
      = 6 * 2 * 4 \\
      = 48 \\
Chữ số khác 0 cuối cùng là: 8 \\
\\
Ví dụ 2: n = 33 [Chữ số thứ 2 từ dưới lên là lẻ]:\\
D(33) = 4 * D(floor(33/5)) * D(3)\\
      = 4 * D(6) * 6 \\
      = 4 * 2 * 6 \\
      = 48 \\
Chữ số khác 0 cuối cùng là: 8 \\
