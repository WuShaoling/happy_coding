#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> trulyMostPopular(vector<string>& names,
                                    vector<string>& synonyms) {
        // 解析 name count
        vector<pair<string, int>> formedNames;
        for (string str : names) {
            int n = str.find_last_of('(');
            string name = str.substr(0, n);
            int count = std::stoi(str.substr(n + 1, str.size() - n - 1));
            _parent[name] = name;
            formedNames.push_back(make_pair(name, count));
        }

        // 解析同名
        vector<pair<string, string>> formedSynonyms;
        for (string synonym : synonyms) {
            int n = synonym.find_first_of(',');
            string str1 = synonym.substr(1, n - 1);
            string str2 = synonym.substr(n + 1, synonym.size() - 2 - n);
            _parent[str1] = str1;
            _parent[str2] = str2;
            formedSynonyms.push_back(make_pair(str1, str2));
        }

        // 合并 parent
        for (pair<string, string> it : formedSynonyms) {
            merge(it.first, it.second);
        }

        // 更新数量
        map<string, int> mm;
        for (pair<string, int> it : formedNames) {
            mm[find(it.first)] += it.second;
        }

        vector<string> res;
        for (auto it : mm) {
            res.push_back(it.first + "(" + to_string(it.second) + ")");
        }
        return res;
    }

    string find(string str) {
        if (_parent[str] == str) return str;
        _parent[str] = find(_parent[str]);
        return _parent[str];
    }

    void merge(string a, string b) {
        string pa = find(a);
        string pb = find(b);
        if (pa != pb) {
            if (pa < pb) {  // 以字典序小的为 parent
                _parent[pb] = pa;
            } else {
                _parent[pa] = pb;
            }
        }
    }

    map<string, string> _parent;
};

void compare(vector<string> res) {
    vector<string> compare = {
        "Fcclu(70)",   "Dnsay(72)",  "Qbmk(45)",    "Unsb(26)",    "Gauuk(75)",
        "Gnplfi(109)", "Hfp(97)",    "Obcbxb(124)", "Ijveol(46)",  "Fpaf(219)",
        "Qiy(26)",     "Mcnef(59)",  "Dhe(79)",     "Jfq(26)",     "Ebov(96)",
        "Ofl(72)",     "Uvkdpn(71)", "Avcp(41)",    "Chycnm(253)", "Koaak(53)",
        "Qyqifg(85)",  "Oltadg(95)", "Mwwvj(70)",   "Naf(3)",      "Ibink(32)",
        "Ucqh(51)",    "Mtz(72)",    "Ard(82)",     "Hcvcgc(97)",  "Knpuq(61)",
        "Yeekgc(11)",  "Ntfr(70)",   "Bnea(179)",   "Weusps(79)",  "Nuq(61)",
        "Drzsnw(87)",  "Chhmx(259)", "Onnev(77)",   "Kufa(95)",    "Avmzs(39)",
        "Okwuq(96)",   "Hljt(51)",   "Npilye(25)",  "Axwtno(57)",  "Kasgmw(95)",
        "Nsgbth(26)",  "Nzaz(51)",   "Msyr(211)",   "Yjc(94)",     "Jvqg(47)",
        "Alrksy(69)",  "Aeax(646)",  "Acohsf(86)",  "Csh(238)",    "Nekuam(17)",
        "Kgabb(236)",  "Fvkhz(104)", "Gbkq(77)",    "Dwifi(237)"};
    sort(compare.begin(), compare.end());
    sort(res.begin(), res.end());
    if (compare.size() != res.size())
        cout << false;
    else {
        for (int i = 0; i < compare.size(); i++) {
            if (compare[i] != res[i])
                cout << compare[i] << "-" << res[i] << endl;
        }
    }
}

int main() {
    Solution s;
    vector<string> names = {
        "Fcclu(70)",  "Ommjh(63)",  "Dnsay(60)",  "Qbmk(45)",   "Unsb(26)",
        "Gauuk(75)",  "Wzyyim(34)", "Bnea(55)",   "Kri(71)",    "Qnaakk(76)",
        "Gnplfi(68)", "Hfp(97)",    "Qoi(70)",    "Ijveol(46)", "Iidh(64)",
        "Qiy(26)",    "Mcnef(59)",  "Hvueqc(91)", "Obcbxb(54)", "Dhe(79)",
        "Jfq(26)",    "Uwjsu(41)",  "Wfmspz(39)", "Ebov(96)",   "Ofl(72)",
        "Uvkdpn(71)", "Avcp(41)",   "Msyr(9)",    "Pgfpma(95)", "Vbp(89)",
        "Koaak(53)",  "Qyqifg(85)", "Dwayf(97)",  "Oltadg(95)", "Mwwvj(70)",
        "Uxf(74)",    "Qvjp(6)",    "Grqrg(81)",  "Naf(3)",     "Xjjol(62)",
        "Ibink(32)",  "Qxabri(41)", "Ucqh(51)",   "Mtz(72)",    "Aeax(82)",
        "Kxutz(5)",   "Qweye(15)",  "Ard(82)",    "Chycnm(4)",  "Hcvcgc(97)",
        "Knpuq(61)",  "Yeekgc(11)", "Ntfr(70)",   "Lucf(62)",   "Uhsg(23)",
        "Csh(39)",    "Txixz(87)",  "Kgabb(80)",  "Weusps(79)", "Nuq(61)",
        "Drzsnw(87)", "Xxmsn(98)",  "Onnev(77)",  "Owh(64)",    "Fpaf(46)",
        "Hvia(6)",    "Kufa(95)",   "Chhmx(66)",  "Avmzs(39)",  "Okwuq(96)",
        "Hrschk(30)", "Ffwni(67)",  "Wpagta(25)", "Npilye(14)", "Axwtno(57)",
        "Qxkjt(31)",  "Dwifi(51)",  "Kasgmw(95)", "Vgxj(11)",   "Nsgbth(26)",
        "Nzaz(51)",   "Owk(87)",    "Yjc(94)",    "Hljt(21)",   "Jvqg(47)",
        "Alrksy(69)", "Tlv(95)",    "Acohsf(86)", "Qejo(60)",   "Gbclj(20)",
        "Nekuam(17)", "Meutux(64)", "Tuvzkd(85)", "Fvkhz(98)",  "Rngl(12)",
        "Gbkq(77)",   "Uzgx(65)",   "Ghc(15)",    "Qsc(48)",    "Siv(47)"};
    vector<string> synonyms = {
        "(Gnplfi,Qxabri)", "(Uzgx,Siv)",    "(Bnea,Lucf)",  "(Qnaakk,Msyr)",
        "(Grqrg,Gbclj)",   "(Uhsg,Qejo)",   "(Csh,Wpagta)", "(Xjjol,Lucf)",
        "(Qoi,Obcbxb)",    "(Npilye,Vgxj)", "(Aeax,Ghc)",   "(Txixz,Ffwni)",
        "(Qweye,Qsc)",     "(Kri,Tuvzkd)",  "(Ommjh,Vbp)",  "(Pgfpma,Xxmsn)",
        "(Uhsg,Csh)",      "(Qvjp,Kxutz)",  "(Qxkjt,Tlv)",  "(Wfmspz,Owk)",
        "(Dwayf,Chycnm)",  "(Iidh,Qvjp)",   "(Dnsay,Rngl)", "(Qweye,Tlv)",
        "(Wzyyim,Kxutz)",  "(Hvueqc,Qejo)", "(Tlv,Ghc)",    "(Hvia,Fvkhz)",
        "(Msyr,Owk)",      "(Hrschk,Hljt)", "(Owh,Gbclj)",  "(Dwifi,Uzgx)",
        "(Iidh,Fpaf)",     "(Iidh,Meutux)", "(Txixz,Ghc)",  "(Gbclj,Qsc)",
        "(Kgabb,Tuvzkd)",  "(Uwjsu,Grqrg)", "(Vbp,Dwayf)",  "(Xxmsn,Chhmx)",
        "(Uxf,Uzgx)"};
    vector<string> res = s.trulyMostPopular(names, synonyms);
    compare(res);
    // for (string str : res) cout << str << endl;
}
