Uses Math;

Var
	n,Ans,x,y:Longint;
	d:Array[0..20] OF Record
	                      c,p,l:Longint;
	                  End;

Procedure Init();
Var
	i:Longint;
Begin
	Readln(n);
	For i:=1 To n Do Readln(d[i].c,d[i].p,d[i].l);
End;

Function Gcd(a,b:Longint):Longint;
Var
	t:Longint;
Begin
	If b=0 Then
	Begin
		x:=1; y:=0;
		Exit(a);
	End;
	Gcd:=Gcd(b,a Mod b);
	t:=x;
	x:=y;
	y:=t-a Div b*y;
End;

Function Check(m:Longint):Boolean;
Var
	i,j,a,b,c,k,Mx:Longint;
Begin
	For i:=1 To n-1 Do
		For j:=i+1 To n Do
		Begin
			a:=d[i].p-d[j].p; b:=-m; c:=d[j].c-d[i].c;
			k:=Gcd(a,b);
			a:=a Div k; b:=b Div k;
			If c Mod k>0 Then Continue;
			Gcd(a,b);
			Mx:=x*(c Div k) Mod b;
			If Mx<0 Then Inc(Mx,Abs(b));
			If Mx<=Min(d[i].l,d[j].l) Then Exit(False);
		End;
	Exit(True);
End;

Procedure Work();
Var
	m:Longint;
Begin
	m:=n;
	While Not Check(m) Do Inc(m);
	Ans:=m;
End;

Begin
	Assign(Input,'1158.in'); Reset(Input);
	//Assign(Output,'data.out'); Rewrite(Output);

	Init();
	Work();
	Writeln(Ans);

	//Close(Input); Close(Output);
End.
