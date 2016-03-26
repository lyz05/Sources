var
n,i,a:longint;{这里integer上限是33767，显然不能符合50000，因此用longint}
T,P,Q:longint;{此处同样}
begin
//assign(input,'simple.in');
//assign(output,'simple.out');
//reset(input);
///=rewrite(output);{都是文件…………}
 readln(n);
 for i:=1 to n do
     begin
        read(a);
          if odd(a)=true then {odd(a),奇数就返回true，else 返回false}
              p:=p+a
           else  q:=q+a;
       end;
T:=abs(P-Q); {abs(a)是绝对值函数，可以直接用，不需要调Math库}
writeln(T);
end.
//close(input);
//close(output);{文件，应该知道吧……}