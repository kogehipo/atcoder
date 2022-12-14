    cin >> N;

    // 全データ入力
    rep(n, 1, N+1) {
        cin >> node[n].U >> node[n].K;
        rep(k, 0, node[n].K) cin >> node[n].V[k];
    }