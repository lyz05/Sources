const
        maxn=300005;
var
        n,i:longint;
        ans:int64;
        a,heap,le,ri,pre,suf,dep:array[0..maxn]of longint;
function max(x,y:longint):longint;
begin
        if x>y then exit(x) else exit(y);
end;
begin
                readln(n);
                for i:=1 to n do begin 
				readln(a[i]);
				heap[a[i]]:=i; 
			 end;
                for i:=1 to n do
                begin
                        le[heap[i]]:=heap[i-1];
                        ri[heap[i-1]]:=heap[i];
                end;
                le[0]:=0; ri[0]:=0;
                for i:=n downto 1 do
                begin
                        pre[i]:=le[i];
                        suf[i]:=ri[i];
                        ri[le[i]]:=ri[i];
				    le[ri[i]]:=le[i];
                end;
                dep[1]:=0; dep[0]:=0;
                for i:=2 to n do
                begin
                        dep[i]:=max(dep[pre[i]],dep[suf[i]])+1;
                end;
                ans:=0;
                for i:=1 to n do
                begin
                        ans:=ans+dep[i];
                        writeln(ans); 
                end;
end.
