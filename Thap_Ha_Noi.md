Ý tưởng của thuật toán đó là sử dụng cột trung gian B và lời giải đệ quy. Hệ thức truy hồi cho bài toán có thể được mô tả theo mẫu sau:  
  
Dịch chuyển ‘N-1’ đĩa từ ‘A’ tới ‘B’, sử dụng C.  
Dịch chuyển đĩa cuối cùng từ ‘A’ tới ‘C’.  
Dịch chuyển ‘N-1’ đĩa từ ‘B’ tới ‘C’, sử dụng A.  
  
Thực hiện các bước sau để giải quyết bài toán này:  
  
Tạo một hàm towerOfHanoi với đối số là N (số đĩa cần di chuyển hiện tại), from_rod, to_rod, aux_rod.  
Gọi hàm với đối số là N – 1 đĩa.  
In ra đĩa dịch chuyển từ from_rod và to_rod.  
Tiếp tục gọi hàm với N – 1 đĩa.  
