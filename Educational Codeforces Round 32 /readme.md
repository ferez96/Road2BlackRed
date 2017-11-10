#Educational Codeforces Round 32 

##Problem A

Độ phức tạp: O(n)

Bài này có thể giải quyết bằng 1 vòng for, kiểm tra a[i] có phải là một 
local extremum hay không theo đúng định nghĩa đề bài.
##Problem B

Độ phức tạp: O(n)

Duyệt tất cả các commands, sau đó xem vị trí cuối cùng cách (0,0) bao nhiêu bước
thì xóa những commands khiến robot di chuyển ra vị trí đó.

Nói ngắn gọn thì nếu sau n command, robot ở vị trí (x,y) thì kết quả cần tìm là:
$n-abs(x)-abs(y)$
##Problem C

Độ phức tạp: O(n)

Với mỗi chữ cái $ch in [a:z]$, tìm chuỗi con dài nhất chứa tối đa 1 ký tự ch.

Kết quả là giá trị nhỏ nhất với 26 chữ cái.
##Problem D

Độ phức tạp: O(1)

Nhận xét: nếu có ít nhất n-k indices đúng vị trí, thì chúng ta sẽ có các trường
hợp số index đúng vị trí là [n-k:n], như vậy đảo bài toán lại là giữ nguyên 
[n-k:n] vị trí và hoán vị [k:0] vị trí còn lại.

Vậy kết quả là: sum( (nCi)*i!|i in [1:k] ) 

Chú ý: số lớn (long long) và i = 0 với i = 1 trùng nhau.
##Problem E

Độ phức tạp: O(2^(n/2))

Nhận xét: 
* Số tổ hợp quá lớn, không thể sinh hết 1 lần được.
* Số giá trị của m quá lớn, không thể quy hoạch động
* Yêu cầu đề chỉ hỏi giá trị mà không hỏi tổng.
* Đáp án là số lớn nhất, bé hơn m trong những tổng có thể sinh ra (sau khi 
modulo m).

Giải: Chia để trị

B1: Chia tập số ra làm 2 phần (tùy tâm), sinh tất cả những tổng có thể có của 2 phần
này, lưu vào 2 set riêng biệt (được biểu diễn bằng cây BlackRed Tree trong c++).

B2: Với mỗi số trong set1, tìm 1 số trong set2 sao cho số này tạo thành "tổng phần 
dư" lớn nhất. (Đã có upper_bound trong c++)

B3: Duyệt lại tất cả các "tổng phần dư" chọn ra số lớn nhất.
##Problem F
##Problem G
