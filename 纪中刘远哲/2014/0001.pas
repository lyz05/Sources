var
n,i,a:longint;{����integer������33767����Ȼ���ܷ���50000�������longint}
T,P,Q:longint;{�˴�ͬ��}
begin
//assign(input,'simple.in');
//assign(output,'simple.out');
//reset(input);
///=rewrite(output);{�����ļ���������}
 readln(n);
 for i:=1 to n do
     begin
        read(a);
          if odd(a)=true then {odd(a),�����ͷ���true��else ����false}
              p:=p+a
           else  q:=q+a;
       end;
T:=abs(P-Q); {abs(a)�Ǿ���ֵ����������ֱ���ã�����Ҫ��Math��}
writeln(T);
end.
//close(input);
//close(output);{�ļ���Ӧ��֪���ɡ���}