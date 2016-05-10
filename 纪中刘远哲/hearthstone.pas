var
        p1,p2,x1,x2:array[0..100001] of longint;
        st,en:array[0..301,0..301] of longint;
        n,a,b,i,j,ans:longint;
        pp:boolean;
begin
        assign(input,'hearthstone.in');
        assign(output,'hearthstone.out');
        reset(input);
        rewrite(output);
        readln(n,a,b);
        ans:=maxlongint;
        for i:=1 to n do begin
                for j:=1 to n do begin
                        read(st[i,j]);
                        x1[st[i,j]]:=x1[st[i,j]]+1;
                end;
                readln;
        end;
        for i:=1 to n do begin
                for j:=1 to n do begin
                        read(en[i,j]);
                        x2[en[i,j]]:=x2[en[i,j]]+1;
                end;
        end;
        for i:=1 to n do for j:=1 to n do if x1[st[i,j]]<>x2[st[i,j]] then begin
                writeln('Fail');
                close(input);
                close(output);
                exit;
        end;
        pp:=true;
        for i:=1 to n do begin
                for j:=1 to n do begin
                        if p1[st[i,j]]<>i then begin
                                p1[st[i,j]]:=i;
                                x1[st[i,j]]:=1;
                        end else inc(x1[st[i,j]]);
                        if p2[en[i,j]]<>i then begin
                                p2[en[i,j]]:=i;
                                x2[en[i,j]]:=1;
                        end else inc(x2[en[i,j]]);
                end;
                for j:=1 to n do begin
                        if(p1[st[i,j]]<>p2[st[i,j]])or
                        (x1[st[i,j]]<>x2[st[i,j]])then begin
                                pp:=false;
                                break;
                        end;
                end;
                if not pp then break;
        end;
        if pp then ans:=a;
        pp:=true;
        fillchar(p1,sizeof(p1),0);
        fillchar(p2,sizeof(p2),0);
        for j:=1 to n do begin
                for i:=1 to n do begin
                        if p1[st[i,j]]<>j then begin
                                p1[st[i,j]]:=j;
                                x1[st[i,j]]:=1;
                        end else inc(x1[st[i,j]]);
                        if p2[en[i,j]]<>j then begin
                                p2[en[i,j]]:=
                                j;
                                x2[en[i,j]]:=1;
                        end else inc(x2[en[i,j]]);
                end;
                for i:=1 to n do begin
                        if(p1[st[i,j]]<>p2[st[i,j]])or
                        (x1[st[i,j]]<>x2[st[i,j]])then begin
                                pp:=false;
                                break;
                        end;
                end;
                if not pp then break;
        end;
        if pp then if ans>b then ans:=b;
        if ans<>maxlongint then writeln(ans)
        else writeln(a+b);
        close(input);
        close(output);
end.
