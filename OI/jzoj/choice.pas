var
        n,i,j,x,ans:longint;
        a:array[0..100000] of longint;
        last:array[-100000..100000] of longint;
begin
        assign(input,'choice6.in');reset(input);
        //assign(output,'choice.out');rewrite(output);
        readln(n);
        for i:=1 to n do begin
                read(x);
                if x=0 then x:=-1;
                a[i]:=a[i-1]+x;
        end;
        for i:=1 to n do
                if (last[a[i]]<>0) or (a[i]=0) then begin
                        if i-last[a[i]]>ans then ans:=i-last[a[i]];
                end else last[a[i]]:=i;
        writeln(ans);
        //close(input);close(output);
end.
