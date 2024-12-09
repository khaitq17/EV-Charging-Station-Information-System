# HỆ THỐNG THÔNG TIN TRẠM SẠC XE ĐIỆN

## Mô tả dự án
Phát triển một Hệ Thống Thông Tin Trạm Sạc Xe Điện (EV Charging Station Information System) sử dụng ngôn ngữ lập trình C. Hệ thống này sẽ chạy trên terminal với giao diện dòng lệnh (CLI), cho phép quản lý, giám sát và điều khiển các trạm sạc xe điện. Dự án áp dụng kiến thức về lập trình C, quản lý bộ nhớ, xử lý file, và thiết kế hệ thống phần mềm.

## Cấu trúc dự án
![image](https://github.com/user-attachments/assets/3ba760aa-fa2a-4c73-93e5-d447eb639b12)

### Menu chính và các chức năng
![image](https://github.com/user-attachments/assets/5d2be5fa-6775-4794-b348-0a9c2fe323bb)

## Mô tả chi tiết các tính năng
### 1. Hiển thị trạng thái trạm sạc
- Tính năng này hiển thị trạng thái hiện tại của trạm sạc, bao gồm công suất sạc, thời gian còn lại, tình trạng kết nối, và các cảnh báo nếu có.
- Hệ thống cũng sẽ hiển thị lịch sử ngắn của các trạng thái gần nhất.

### 2. Bắt đầu sạc
- Khi người dùng chọn chức năng này, hệ thống sẽ khởi động quá trình sạc với các thông số mặc định hoặc được cài đặt trước.
- Người dùng có thể điều chỉnh công suất sạc và thời gian sạc trước khi bắt đầu quá trình.

### 3. Dừng sạc
- Tính năng này cho phép người dùng kết thúc quá trình sạc và ghi nhận các thông số cuối cùng vào hệ thống.
- Hệ thống cũng sẽ thực hiện kiểm tra nhanh để đảm bảo rằng quá trình sạc đã được hoàn thành an toàn.

### 4. Xem lịch sử sạc
- Tính năng này cho phép người dùng xem chi tiết lịch sử sạc của trạm, bao gồm thời gian, công suất, và trạng thái của mỗi lần sạc.
- Người dùng có thể lọc kết quả theo ngày hoặc trạng thái sạc để dễ dàng tra cứu.

### 5. Cài đặt trạm sạc
- Tính năng này cho phép người dùng cài đặt và điều chỉnh các thông số của trạm sạc như công suất tối đa, thời gian sạc tối đa, và ngưỡng cảnh báo nhiệt độ.
- Người dùng cũng có thể khởi tạo hoặc đặt lại các thiết lập của trạm sạc về mặc định.

### 6. Kiểm tra tình trạng kết nối
- Hệ thống sẽ thực hiện kiểm tra kết nối giữa trạm sạc và xe điện, đảm bảo rằng kết nối ổn định và không có lỗi.
- Người dùng có thể xem thông tin chi tiết về chất lượng kết nối, bao gồm độ mạnh của tín hiệu và độ trễ.

### 7. Hiệu chuẩn cảm biến
- Tính năng này cho phép người dùng hiệu chuẩn các cảm biến của trạm sạc như cảm biến nhiệt độ, dòng điện, và điện áp.
- Hệ thống sẽ hướng dẫn người dùng qua các bước cần thiết để đảm bảo rằng các cảm biến đang hoạt động chính xác.

### 8. Thoát
- Chức năng này cho phép người dùng thoát khỏi ứng dụng. Trước khi thoát, hệ thống sẽ xác nhận và ghi lại các dữ liệu cần thiết để đảm bảo không có thông tin bị mất.
