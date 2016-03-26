Const
        Maxn=500005;
Var
        head: array[0..maxn]of Longint;
        tot,ex: array[0..maxn]of Int64;
        next,t: array[0..2*maxn]of Longint;
        v: array[0..2*maxn]of Int64;
        time: array[0..2*maxn]of int64;
        n,i,x,y,z,sum: Longint;
        max,ans,tmp: Int64;
Procedure Insert(x,y,z: Longint);
Begin
        Inc(sum);
        t[sum]:=y;
        time[sum]:=z;
        Next[sum]:=Head[x];
        Head[x]:=sum;
End;
Procedure findmax(x,fa: Longint);
Var
        tmp: Longint;
Begin
        tmp:=Head[x];
        if tot[x]>Max then Max:=tot[x];
        While tmp<>0 Do Begin
                if t[tmp]=fa Then Begin
                        tmp:=Next[tmp];
                        Continue;
                End;
                tot[t[tmp]]:=tot[x]+time[tmp];
                findmax(t[tmp],x);
                tmp:=Next[tmp];
        End;
End;
Procedure pq(x,fa: Longint);
Var
        tmp,js: Longint;
        k,min: int64;
        bz: Boolean;
Begin
        min:=MaxLongint*maxLongint;
        js:=0;
        tmp:=head[x];
        bz:=False;
        While tmp<>0 Do Begin
                if t[tmp]=fa Then Begin
                        Tmp:=Next[tmp];
                        Continue;
                End;
                bz:=True;
                Inc(js);
                pq(t[tmp],x);
                k:=ex[t[tmp]];
                if k<min Then min:=k;
                tmp:=Next[tmp];
        End;
        if Not bz then Begin
                ans:=ans+(max-tot[x]);
                ex[x]:=max-tot[x];
                Exit;
        End;
        ans:=ans-min*(js-1);
        ex[x]:=min;
end;
Begin
        Readln(n);
        For i:=1 To n-1 Do Begin
                Readln(x,y,z);
                Insert(x,y,z);
                Insert(y,x,z);
        End;
        FindMax(1,0);
        pq(1,0);
        Writeln(ans);
        Close(Input);Close(Output);
End.
