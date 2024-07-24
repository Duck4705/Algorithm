Đọc từng token trong biểu thức infix từ trái qua phải, với mỗi token ta thực hiện các bước sau:  
  
  +Nếu là toán hạng: cho ra output.  
  +Nếu là dấu đóng ngoặc “)“: cho vào stack  
  +Nếu là dấu mở ngoặc “(”: lấy các toán tử trong stack ra và cho vào output cho đến khi gặp dấu đóng ngoặc “)“. (Dấu đóng ngoặc cũng phải được đưa ra khỏi stack)  
     
  
  +Nếu là toán tử:  
     -Chừng nào ở đỉnh stack là toán tử và toán tử đó có độ ưu tiên lớn hơn toán tử hiện tại thì lấy toán tử đó ra khỏi stack và cho ra output.  
     -Đưa toán tử hiện tại vào stack  
     -Sau khi duyệt hết biểu thức infix, nếu trong stack còn phần tử thì lấy các token trong đó ra và cho lần lượt vào output. Cuối cùng là đảo ngược biểu thức một lần nữa và ta sẽ thu được kết quả.  