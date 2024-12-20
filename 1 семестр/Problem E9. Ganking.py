# Statement
# Popular on-line game "Attack Of The Moderns 3" is played by two teams of 5 players each. During the match, players run around the map and try to kill members of opposing team by attacking them with various weapons and magic spells. Killed players respawn after a certain period of time.
# Players of the first team are numbered from 1 to 5, players of the second team are numbered from 6 to 10. All attacks are recorded by the game for statistics gathering. Each attack is described by values t,a,v,k, where t is a time in seconds since the game start, a — the number of the attacking player, v — the number of the player being attacked, k=1 if this attack killed the victim and 0 otherwise.
# Gank is an event when one or more players attack and kill a single opponent while his teammates are elsewhere and unable to help. Specifically: let G be a set of players who attacked the victim during the last T seconds of the game before the kill. A kill is counted as a gank, if in that period of time:the victim only attacked players from set G, and players from set G attacked and were attacked only by the victim.
# All the players from the set G who attacked the victim of the gank are considered the participants of this gank.Your program must, given the value of T and a sequence of N attack descriptions, count the number of ganks each player has participated in.
# Input file format
# Input file contains integers NT followed by N quartets of integers tiaivik.
# Output file format
# Output file must contain 10 integers — the numbers of ganks for each player.
# Constraints1≤N≤10000, 1≤ti≤ti+1≤10^5, 1≤T≤10^5. Either 1≤ai≤5<vi≤10 or 1≤vi≤5<ai≤10. Time between sequential kills of the same victim is greater than T.
# Sample tests
# No.	Input file (input.txt)	Output file (output.txt)
# 1	7 4                     0 1 2 0 0 0 0 1 0 0 
#     1 1 6 0
#     2 2 6 0
#     5 3 6 1
#     10 7 1 1
#     10 7 2 1
#     20 8 1 1
#     20 3 7 1
def check(now_id, data, size_data, good_time):
    fix_time = data[now_id]['time_line']
    fix_victim = data[now_id]['victim_player']
    set_G = [0] * 11
    for i in range(now_id, -1, -1):
        if fix_time - data[i]['time_line'] >= good_time:
            break
        if data[i]['victim_player'] == fix_victim:
            set_G[data[i]['attacking_player']] = 1
    for i in range(now_id + 1, size_data):
        if data[i]['time_line'] != fix_time:
            break
        if data[i]['victim_player'] == fix_victim:
            set_G[data[i]['attacking_player']] = 1
    for i in range(now_id + 1, size_data):
        if data[i]['time_line'] != fix_time:
            break
        if set_G[data[i]['attacking_player']] == 1 and data[i]['victim_player'] != fix_victim:
            return
        if set_G[data[i]['victim_player']] == 1 and data[i]['attacking_player'] != fix_victim:
            return
        if data[i]['attacking_player'] == fix_victim and set_G[data[i]['victim_player']] != 1:
            return
    for i in range(now_id - 1, -1, -1):
        if fix_time - data[i]['time_line'] >= good_time:
            break
        if set_G[data[i]['attacking_player']] == 1 and data[i]['victim_player'] != fix_victim:
            return
        if set_G[data[i]['victim_player']] == 1 and data[i]['attacking_player'] != fix_victim:
            return
        if data[i]['attacking_player'] == fix_victim and set_G[data[i]['victim_player']] != 1:
            return
    for i in range(1, 11):
        result[i] += set_G[i]
    return
with open("input.txt", "r") as inp, open("output.txt", "w") as out:
    n, t = map(int, inp.readline().split())
    data = []
    result = [-1] + [0] * 10
    for _ in range(n):
        a, b, c, d = map(int, inp.readline().split())
        data.append({'time_line': a, 'attacking_player': b, 'victim_player': c, 'result_line': d})
    for id_line in range(n):
        if data[id_line]['result_line'] == 1:
            check(id_line, data, n, t)
    out.write(' '.join(map(str, result[1:])))