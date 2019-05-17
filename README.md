# Premiere Subtitle Generator
<img src="https://i.loli.net/2017/12/15/5a335c9e52d20.png" alt="Psg" width="64">

## Alternative
由于从 pr cc 2017 就已经不再支持导出旧版字幕了，所以这个工具也宣告失效。当然你若是使用旧版的 pr 且能导出旧版字幕，那么这个小工具依然有效。

另一方面，虽然不支持导出旧版字幕了，但是它支持 srt 字幕，因此我就写了个 Python 脚本，一键生成 srt 字幕。

```bash
>> git clone https://github.com/LewisTian/PremiereSubtitle.git
>> cd PremiereSubtitle/dist

>> python srt_subtitles.py 3
# or 
>> ./srt_subtitles.exe 3
```

将你要生成的字幕写入脚本同目录的 txt 文件中，然后双击运行即可。

上面命令中的 `3` 是指定时间间隔，默认是 `5`。

## Preview
![preview.gif](https://i.loli.net/2017/12/03/5a23f6a9390f5.gif)

## Installing
[download link](https://github.com/LewisTian/Premiere-Subtitle/releases)

### Screenshot
<img src="https://i.loli.net/2017/08/19/59983b985aaef.png" alt="PrSubtitle" width="350" />

### Video
https://www.bilibili.com/video/av16728820/

## Licence
- [MIT](https://github.com/LewisTian/PremiereSubtitle/blob/master/LICENSE)
- 本软件不得用于商业用途，仅做学习交流。
