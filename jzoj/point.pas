const
    maxn=100000;
var
    p,E:array[0..maxn] of longint;
    f:array[2..maxn] of boolean;
    n,i,j:longint;
    ans:int64;
begin
    //assign(input,'point.in');reset(input);
    //assign(output,'point.out');rewrite(output);

    readln(n);
    if n=1 then writeln(0)
    else begin
        p[0]:=0;
        for i:=2 to n do begin
            if not f[i] then begin
	    inc(p[0]);
	    p[p[0]]:=i;
	    E[i]:=i-1;
            end;
            for j:=1 to p[0] do begin
                if i*p[j]>n then break;
                f[i*p[j]]:=true;
                if i mod p[j]=0 then begin
		       	E[i*p[j]]:=E[i]*(E[p[j]]+1);
		       	break;
	       	end
                else E[i*p[j]]:=E[i]*E[p[j]];
            end;
        end;
        ans:=0;
        for i:=2 to n-1 do ans:=ans+E[i];
        writeln(ans*2+3);
    end;

    //close(input);close(output);
end.
