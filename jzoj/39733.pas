Const
        Maxn=1000005;
Var
        fa,head,c,xx: array[0..maxn]of Longint;
        next,t,num: array[0..2*maxn]of Longint;
        bz: array[0..maxn]of Boolean;
        n,m,i,x,y,sum: Longint;
Procedure Insert(x,y,op: Longint);
Begin
        Inc(sum);
        t[sum]:=y;
        num[sum]:=op;
        Next[sum]:=Head[x];
        Head[x]:=sum;
end;
Procedure find(now,father,w: Longint);
var
        tmp: Longint;
Begin
        fa[now]:=Father;
        c[now]:=w;
        tmp:=Head[now];
        While tmp>0 Do Begin
                if t[tmp]<>father Then Begin
                        xx[t[tmp]]:=num[tmp];
                        find(t[tmp],now,w+1);
                End;
                tmp:=next[tmp];
        End;
End;
Procedure search(y: Longint);
Var
        tmp: Longint;
Begin
        tmp:=y;
        While tmp<>1 Do Begin
                if bz[tmp] Then Begin
                        writeln(xx[tmp]);
                        Exit;
                End;
                tmp:=fa[tmp];
        End;
        writeln(0);
end;
Procedure Change(y,z: Longint);
Var
        ny,nz,tmp1,tmp2,tr: Longint;
Begin
        tmp1:=c[y];
        tmp2:=c[z];
        ny:=y;
        nz:=z;
        if tmp1>tmp2 Then begin
                While tmp1>tmp2 Do Begin
                        bz[ny]:=True;
                        ny:=fa[ny];
                        Dec(tmp1);
                End;
        End
        Else if tmp1<tmp2 Then Begin
                While tmp1<tmp2 Do Begin
                        bz[nz]:=True;
                        nz:=fa[nz];
                        Dec(tmp2);
                end;
        End;
        While nz<>ny Do Begin
                bz[ny]:=True;
                bz[nz]:=True;
                ny:=fa[ny];
                nz:=fa[nz];
        End;
End;
Procedure Main();
var
        i,x,y,z: Longint;
Begin
        For i:=1 To m Do Begin
                Read(x);
                if x=1 Then Begin
                        Readln(y);
                        search(y);
                End
                Else Begin
                        Readln(y,z);
                        change(y,z);
                End;
        End;
End;
Begin
        Readln(n,m);
        For i:=1 To n-1 Do Begin
                Readln(x,y);
                Insert(x,y,i);
                Insert(y,x,i);
        End;
        find(1,0,1);
        Main();
End.
