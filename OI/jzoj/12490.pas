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
			//�ܻ�õ�����
                        if (Not b[n-j+1][i])or(v[i][j-1]>=k) Then v[i][j]:=v[i][j-1]+1
			//�����ǰ�����н����ӵ�������Ҫ�ӵ���ǰ���ǵ�ǰ�ӵ���û�þ�
                        Else v[i][j]:=v[i][j-1];
                End;
        End;
        Fillchar(f,sizeof(f),255);//����ֵ-1
	//f����ǰi�з����˹�j���ӵ����������
        For i:=1 To n Do
                if (v[1][i]<=k) Then f[1][v[1][i]]:=tot[1][i];
        f[1][0]:=0;
        For i:=1 to m-1 Do
                For j:=0 To k Do Begin
                        if f[i][j]=-1 Then Continue;
                        f[i+1][j]:=Max(f[i+1][j],f[i][j]);
                        For l:=1 To n Do Begin
                                if v[i+1][l]+j>k Then Break;
				//�ﵽ��һ����Ҫ���ӵ����Ѿ��õ��ӵ����������ӵ�
                                f[i+1][v[i+1][l]+j]:=Max(f[i+1][v[i+1][l]+j],f[i][j]+tot[i+1][l]);
                                ans:=Max(f[i+1][v[i+1][l]+j],ans);
                        End;
                End;
        Writeln(ans);
End.
