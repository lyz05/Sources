Uses Math;
Const
        Maxn=205;
Var
        a,v,tot: array[0..maxn,0..maxn]of Longint;
        b: array[0..maxn,0..maxn]of Boolean;
        f: array[0..maxn,0..maxn]of Longint;
        n,m,k,i,j,l,ans: Longint;
        c: Char;
Begin
	assign(input,'1249.in');reset(input);
	//assign(output,'.out');rewrite(output);

        Readln(n,m,k);
        For i:=1 To n Do Begin
                For j:=1 To m Do Begin
                        Read(a[i][j],c,c);
                        if c='Y' Then b[i][j]:=True;
                End;
        End;
        For i:=1 To m DO Begin
                For j:=1 To n Do Begin
                        tot[i][j]:=tot[i][j-1]+a[n-j+1][i];
			//能获得的利益
                        if (Not b[n-j+1][i])or(v[i][j-1]>=k) Then v[i][j]:=v[i][j-1]+1
			//如果当前这里有奖励子弹，则不需要子弹，前提是当前子弹还没用尽
                        Else v[i][j]:=v[i][j-1];
                End;
        End;
        Fillchar(f,sizeof(f),255);//赋初值-1
	//f代表前i列发射了共j发子弹的最大利益
        For i:=1 To n Do
                if (v[1][i]<=k) Then f[1][v[1][i]]:=tot[1][i];
        f[1][0]:=0;
        For i:=1 to m-1 Do
                For j:=0 To k Do Begin
                        if f[i][j]=-1 Then Continue;
                        f[i+1][j]:=Max(f[i+1][j],f[i][j]);
                        For l:=1 To n Do Begin
                                if v[i+1][l]+j>k Then Break;
				//达到这一层需要的子弹与已经用的子弹，超过总子弹
                                f[i+1][v[i+1][l]+j]:=Max(f[i+1][v[i+1][l]+j],f[i][j]+tot[i+1][l]);
                                ans:=Max(f[i+1][v[i+1][l]+j],ans);
                        End;
                End;
        Writeln(ans);
End.
